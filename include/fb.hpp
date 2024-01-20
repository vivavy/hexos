#include <uart.hpp>

#include <mbox.hpp>
#include <cppdlc.hpp>


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
} packed psf_t;
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
} packed sfn_t;
extern skip u8 _binary_res_fonts_font_sfn_sfn_start;


ns fb {
    u32 width, height, pitch, isrgb;   /* dimensions and channel order */
    u8 *buffer;                         /* raw frame buffer address */

    /**
     * Set screen resolution
     */
    nil init(u32 scr_width, u32 scr_height, u32 scr_depth) {
        /* newer qemu segfaults if we don't wait here a bit */
        //wait_ms(100000);

        mbox::buffer[0] = 35*4;
        mbox::buffer[1] = MBOX_REQUEST;

        mbox::buffer[2] = 0x48003;  //set phy wh
        mbox::buffer[3] = 8;
        mbox::buffer[4] = 8;
        mbox::buffer[5] = scr_width;         //FrameBufferInfo.width
        mbox::buffer[6] = scr_height;          //FrameBufferInfo.height

        mbox::buffer[7] = 0x48004;  //set virt wh
        mbox::buffer[8] = 8;
        mbox::buffer[9] = 8;
        mbox::buffer[10] = scr_width;        //FrameBufferInfo.virtual_width
        mbox::buffer[11] = scr_height;         //FrameBufferInfo.virtual_height

        mbox::buffer[12] = 0x48009; //set virt offset
        mbox::buffer[13] = 8;
        mbox::buffer[14] = 8;
        mbox::buffer[15] = 0;           //FrameBufferInfo.x_offset
        mbox::buffer[16] = 0;           //FrameBufferInfo.y.offset

        mbox::buffer[17] = 0x48005; //set depth
        mbox::buffer[18] = 4;
        mbox::buffer[19] = 4;
        mbox::buffer[20] = scr_depth;          //FrameBufferInfo.depth

        mbox::buffer[21] = 0x48006; //set pixel order
        mbox::buffer[22] = 4;
        mbox::buffer[23] = 4;
        mbox::buffer[24] = 1;           //RGB, not BGR preferably

        mbox::buffer[25] = 0x40001; //get framebuffer, gets alignment on request
        mbox::buffer[26] = 8;
        mbox::buffer[27] = 8;
        mbox::buffer[28] = 4096;        //FrameBufferInfo.pointer
        mbox::buffer[29] = 0;           //FrameBufferInfo.size

        mbox::buffer[30] = 0x40008; //get pitch
        mbox::buffer[31] = 4;
        mbox::buffer[32] = 4;
        mbox::buffer[33] = 0;           //FrameBufferInfo.pitch

        mbox::buffer[34] = MBOX_TAG_LAST;

        //this might not return exactly what we asked for, could be
        //the closest supported resolution instead
        if(mbox::call(MBOX_CH_PROP) && mbox::buffer[20]==32 && mbox::buffer[28]!=0) {
            mbox::buffer[28]&=0x3FFFFFFF;   //convert GPU address to ARM address
            width=mbox::buffer[5];          //get actual physical width
            height=mbox::buffer[6];         //get actual physical height
            pitch=mbox::buffer[33];         //get number of bytes per line
            isrgb=mbox::buffer[24];         //get the actual channel order
            buffer = (u8 *)((u32)mbox::buffer[28]);
        } else {
            uart::puts("Unable to set screen resolution to");
            uart::hex(scr_width);
            uart::puts("x");
            uart::hex(scr_height);
            uart::puts("x");
            uart::hex(scr_depth);
            uart::puts("\n");
        }
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


    nil proprint(int x, int y, char *s)
    {
        // get our font
        sfn_t *font = (sfn_t*)&_binary_res_fonts_font_sfn_sfn_start;
        u8 *ptr, *chr, *frg;
        u32 c;
        unsigned long o, p;
        int i, j, k, l, m, n;

        while(*s) {
            // UTF-8 to UNICODE code point
            if((*s & 128) != 0) {
                if(!(*s & 32)) { c = ((*s & 0x1F)<<6)|(*(s+1) & 0x3F); s += 1; } else
                if(!(*s & 16)) { c = ((*s & 0xF)<<12)|((*(s+1) & 0x3F)<<6)|(*(s+2) & 0x3F); s += 2; } else
                if(!(*s & 8)) { c = ((*s & 0x7)<<18)|((*(s+1) & 0x3F)<<12)|((*(s+2) & 0x3F)<<6)|(*(s+3) & 0x3F); s += 3; }
                else c = 0;
            } else c = *s;
            s++;
            // handle carrige return
            if(c == '\r') {
                x = 0; continue;
            } else
            // new line
            if(c == '\n') {
                x = 0; y += font->height; continue;
            }
            // find glyph, look up "c" in Character Table
            for(ptr = (u8*)font + font->characters_offs, chr = 0, i = 0; i < 0x110000; i++) {
                if(ptr[0] == 0xFF) { i += 65535; ptr++; }
                else if((ptr[0] & 0xC0) == 0xC0) { j = (((ptr[0] & 0x3F) << 8) | ptr[1]); i += j; ptr += 2; }
                else if((ptr[0] & 0xC0) == 0x80) { j = (ptr[0] & 0x3F); i += j; ptr++; }
                else { if((u32)i == c) { chr = ptr; break; } ptr += 6 + ptr[1] * (ptr[0] & 0x40 ? 6 : 5); }
            }
            if(!chr) continue;
            // uncompress and display fragments
            ptr = chr + 6; o = (u32)buffer + y * pitch + x * 4;
            for(i = n = 0; i < chr[1]; i++, ptr += chr[0] & 0x40 ? 6 : 5) {
                if(ptr[0] == 255 && ptr[1] == 255) continue;
                frg = (u8*)font + (chr[0] & 0x40 ? ((ptr[5] << 24) | (ptr[4] << 16) | (ptr[3] << 8) | ptr[2]) :
                    ((ptr[4] << 16) | (ptr[3] << 8) | ptr[2]));
                if((frg[0] & 0xE0) != 0x80) continue;
                o += (int)(ptr[1] - n) * pitch; n = ptr[1];
                k = ((frg[0] & 0x1F) + 1) << 3; j = frg[1] + 1; frg += 2;
                for(m = 1; j; j--, n++, o += pitch)
                    for(p = o, l = 0; l < k; l++, p += 4, m <<= 1) {
                        if(m > 0x80) { frg++; m = 1; }
                        if(*frg & m) *((u32*)p) = 0xFFFFFF;
                    }
            }
            // add advances
            x += chr[4]+1; y += chr[5];
        }
    }

    nil flush() {
        for (u32 offset = 0; offset < width * height; offset++) {
            buffer[offset] = 0x00;
        }
    }
}