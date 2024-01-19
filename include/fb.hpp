#ifndef __FRAMEBUFFER__
#define __FRAMEBUFFER__

#include <cppdlc.hpp>
#include <time.hpp>
#include <mbox.hpp>
#include <uart.hpp>

typedef struct FramebufferInfo {
    u32 width, height, depth;
} FBInfo;

typedef struct {
    u32 magic;
    u32 version;
    u32 headersize;
    u32 flags;
    u32 numglyph;
    u32 bytesperglyph;
    u32 height;
    u32 width;
    u8 glyphs;
} __attribute__((packed)) psf_t;

extern skip u8 _binary_res_fonts_font_psf_psf_start;


typedef struct {
    u8  magic[4];
    u32   size;
    u8  type;
    u8  features;
    u8  width;
    u8  height;
    u8  baseline;
    u8  underline;
    u16 fragments_offs;
    u32   characters_offs;
    u32   ligature_offs;
    u32   kerning_offs;
    u32   cmap_offs;
} __attribute__((packed)) sfn_t;

extern skip u8 _binary_res_fonts_font_sfn_sfn_start;


u32 width, height, pitch, isrgb;   /* dimensions and channel order */

namespace fb {
    u8 *buffer;                  /* raw frame buffer address */
    FBInfo fb_info;
    nil init() {
        time::sleep(100000);

        mbox::buffer[0] = 140;
        mbox::buffer[1] = MBOX_REQUEST;

        mbox::buffer[2] = 294915;           //set phy wh
        mbox::buffer[3] = 8;
        mbox::buffer[4] = 8;
        mbox::buffer[5] = fb_info.width;     //FrameBufferInfo.width
        mbox::buffer[6] = fb_info.height;    //FrameBufferInfo.height

        mbox::buffer[7] = 294916;           //set virt wh
        mbox::buffer[8] = 8;
        mbox::buffer[9] = 8;
        mbox::buffer[10] = fb_info.width;    //FrameBufferInfo.virtual_width
        mbox::buffer[11] = fb_info.height;   //FrameBufferInfo.virtual_height

        mbox::buffer[12] = 294921;          //set virt offset
        mbox::buffer[13] = 8;
        mbox::buffer[14] = 8;
        mbox::buffer[15] = 0;                //FrameBufferInfo.x_offset
        mbox::buffer[16] = 0;                //FrameBufferInfo.y.offset

        mbox::buffer[17] = 294917;          //set depth
        mbox::buffer[18] = 4;
        mbox::buffer[19] = 4;
        mbox::buffer[20] = fb_info.depth;    //FrameBufferInfo.depth

        mbox::buffer[21] = 294918;          //set pixel order
        mbox::buffer[22] = 4;
        mbox::buffer[23] = 4;
        mbox::buffer[24] = 1;                //RGB, not BGR preferably

        mbox::buffer[25] = 262145;          //get framebuffer,
        //                                  //gets alignment on request
        mbox::buffer[26] = 8;
        mbox::buffer[27] = 8;
        mbox::buffer[28] = 4096;             //FrameBufferInfo.pointer
        mbox::buffer[29] = 0;                //FrameBufferInfo.size

        mbox::buffer[30] = 262152;          //get pitch
        mbox::buffer[31] = 4;
        mbox::buffer[32] = 4;
        mbox::buffer[33] = 0;                //FrameBufferInfo.pitch

        mbox::buffer[34] = MBOX_TAG_LAST;

        //this might not return exactly what we asked for, could be
        //the closest supported resolution instead
        if     (mbox::call(MBOX_CH_PROP) &&
                mbox::buffer[20] == 32   &&
                mbox::buffer[28] != 0) {
            mbox::buffer[28] &= 1073741823;   //convert GPU address to ARM address
            width = mbox::buffer[5];          //get actual physical width
            height= mbox::buffer[6];          //get actual physical height
            pitch = mbox::buffer[33];         //get number of bytes per line
            isrgb = mbox::buffer[24];         //get the actual channel order
            fb::buffer=(u8*)((u64)mbox::buffer[28]);
        } else uart::puts("Unable to set screen resolution to 1024x768x32\n");
    }

    nil print(int x, int y, char *s)
    {
        // get our font
        psf_t *font = (psf_t*)&_binary_res_fonts_font_psf_psf_start;
        // draw next character if it's not zero
        while(*s) {
            // get the offset of the glyph. Need to adjust this to support unicode table
            u8 *glyph = (u8*)&_binary_res_fonts_font_psf_psf_start +
            font->headersize + (*((u8*)s)<font->numglyph?*s:0)*font->bytesperglyph;
            // calculate the offset on screen
            int offs = (y * pitch) + (x * 4);
            // variables
            int i,j, line,mask, bytesperline=(font->width+7)/8;
            // handle carrige return
            if(*s == '\r') {
                x = 0;
            } else
            // new line
            if(*s == '\n') {
                x = 0; y += font->height;
            } else {
                // display a character
                for(j=0;j<font->height;j++){
                    // display one row
                    line=offs;
                    mask=1<<(font->width-1);
                    for(i=0;i<font->width;i++){
                        // if bit set, we use white color, otherwise black
                        *((u32*)(buffer + line))=((int)*glyph) & mask?0xFFFFFF:0;
                        mask>>=1;
                        line+=4;
                    }
                    // adjust to next line
                    glyph+=bytesperline;
                    offs+=pitch;
                }
                x += (font->width+1);
            }
            // next character
            s++;
        }
    }

    nil flush() {
        for (u32 fb_offset = 0; fb_offset < width * height; fb_offset++) {
            buffer[fb_offset] = 0;
        }
    }
};

#endif
