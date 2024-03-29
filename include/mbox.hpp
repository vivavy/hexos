#ifndef __MESSAGEBOX__
#define __MESSAGEBOX__

#include <gpio.hpp>
#include <cppdlc.hpp>

/* mailbox message buffer */
volatile unsigned int  __attribute__((aligned(16))) mbox_buffer[36];

#define MBOX_REQUEST    0

/* channels */
#define MBOX_CH_POWER   0
#define MBOX_CH_FB      1
#define MBOX_CH_VUART   2
#define MBOX_CH_VCHIQ   3
#define MBOX_CH_LEDS    4
#define MBOX_CH_BTNS    5
#define MBOX_CH_TOUCH   6
#define MBOX_CH_COUNT   7
#define MBOX_CH_PROP    8

/* tags */
#define MBOX_TAG_SETPOWER       0x28001
#define MBOX_TAG_GETSERIAL      0x10004
#define MBOX_TAG_SETCLKRATE     0x38002
#define MBOX_TAG_LAST           0

#define VIDEOCORE_MBOX  (MMIO_BASE + 0x0000B880)
#define MBOX_READ       ((volatile u32*)(VIDEOCORE_MBOX + 0x0))
#define MBOX_POLL       ((volatile u32*)(VIDEOCORE_MBOX + 0x10))
#define MBOX_SENDER     ((volatile u32*)(VIDEOCORE_MBOX + 0x14))
#define MBOX_STATUS     ((volatile u32*)(VIDEOCORE_MBOX + 0x18))
#define MBOX_CONFIG     ((volatile u32*)(VIDEOCORE_MBOX + 0x1C))
#define MBOX_WRITE      ((volatile u32*)(VIDEOCORE_MBOX + 0x20))
#define MBOX_RESPONSE   0x80000000
#define MBOX_FULL       0x80000000
#define MBOX_EMPTY      0x40000000

namespace mbox {
    int call(u8 ch)
    {
        unsigned int r = (((u32)((u64) &mbox_buffer) & ~0xF) | (ch & 0xF));
        /* wait until we can write to the mailbox */
        do {
            asm volatile("nop");
        } while (*MBOX_STATUS & MBOX_FULL);
        /* write the address of our message to the mailbox with channel identifier */
        *MBOX_WRITE = r;
        /* now wait for the response */
        while (1) {
            /* is there a response? */
            do {
                asm volatile("nop");
            } while( *MBOX_STATUS & MBOX_EMPTY);
            /* is it a response to our message? */
            if(r == *MBOX_READ)
                /* is it a valid successful response? */
                return mbox_buffer[1] == MBOX_RESPONSE;
        }
        return 0;
    }
}
#endif
