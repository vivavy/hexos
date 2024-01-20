#ifndef __MESSAGEBOX__
#define __MESSAGEBOX__

#include <gpio.hpp>
#include <cppdlc.hpp>

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
#define MBOX_TAG_SETPOWER       163841
#define MBOX_TAG_GETSERIAL      65540
#define MBOX_TAG_SETCLKRATE     229378
#define MBOX_TAG_LAST           0

#define VIDEOCORE_MBOX  (MMIO_BASE + 47232)
#define MBOX_READ       ((skip u32*)(VIDEOCORE_MBOX + 0))
#define MBOX_POLL       ((skip u32*)(VIDEOCORE_MBOX + 16))
#define MBOX_SENDER     ((skip u32*)(VIDEOCORE_MBOX + 20))
#define MBOX_STATUS     ((skip u32*)(VIDEOCORE_MBOX + 24))
#define MBOX_CONFIG     ((skip u32*)(VIDEOCORE_MBOX + 28))
#define MBOX_WRITE      ((skip u32*)(VIDEOCORE_MBOX + 32))
#define MBOX_RESPONSE   2147483648U
#define MBOX_FULL       2147483648U
#define MBOX_EMPTY      1073741824U

namespace mbox {
    /* mailbox message buffer */
    skip u32 ALIGN(16) buffer[36];

    u32 call(u8 ch) {
        u32 r = (((u32)((u32)&buffer)&~15) | (ch&15));
        /* wait until we can write to the mailbox */
        do asm skip ("nop"); while (*MBOX_STATUS & MBOX_FULL);
        /* write the address of our message to the mailbox with channel identifier */
        *MBOX_WRITE = r;
        /* now wait for the response */
        while (1) {
            /* is there a response? */
            do asm skip("nop"); while (*MBOX_STATUS & MBOX_EMPTY);
            /* is it a response to our message? */
            if (r == *MBOX_READ)
                /* is it a valid successful response? */
                return buffer[1] == MBOX_RESPONSE;
        }
        return 0;
    }
}
#endif
