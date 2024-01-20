#ifndef __UART0DEV__
#define __UART0DEV__

#include <cppdlc.hpp>
#include <gpio.hpp>
#include <mbox.hpp>

/* PL011 UART registers */
#define UART0_DR        ((skip u32*)(MMIO_BASE + 0x00201000))
#define UART0_FR        ((skip u32*)(MMIO_BASE + 0x00201018))
#define UART0_IBRD      ((skip u32*)(MMIO_BASE + 0x00201024))
#define UART0_FBRD      ((skip u32*)(MMIO_BASE + 0x00201028))
#define UART0_LCRH      ((skip u32*)(MMIO_BASE + 0x0020102C))
#define UART0_CR        ((skip u32*)(MMIO_BASE + 0x00201030))
#define UART0_IMSC      ((skip u32*)(MMIO_BASE + 0x00201038))
#define UART0_ICR       ((skip u32*)(MMIO_BASE + 0x00201044))

/*/
 * Set baud rate and characteristics (115200 8N1) and map to GPIO
/*/

namespace uart {
    void init() {
        register unsigned int r;

        // initialize UART
        *UART0_CR = 0;         // turn off UART0

        // set up clock for consistent divisor values
        mbox::buffer[0] = 9*4;
        mbox::buffer[1] = MBOX_REQUEST;
        mbox::buffer[2] = MBOX_TAG_SETCLKRATE; // set clock rate
        mbox::buffer[3] = 12;
        mbox::buffer[4] = 8;
        mbox::buffer[5] = 2;           // UART clock
        mbox::buffer[6] = 4000000;     // 4Mhz
        mbox::buffer[7] = 0;           // clear turbo
        mbox::buffer[8] = MBOX_TAG_LAST;
        mbox::call(MBOX_CH_PROP);

        // map UART0 to GPIO pins
        r=*GPFSEL1;
        r&=~((7<<12)|(7<<15)); // gpio14, gpio15
        r|=(4<<12)|(4<<15);    // alt0
        *GPFSEL1 = r;
        *GPPUD = 0;            // enable pins 14 and 15
        r=150; while(r--) { asm volatile("nop"); }
        *GPPUDCLK0 = (1<<14)|(1<<15);
        r=150; while(r--) { asm volatile("nop"); }
        *GPPUDCLK0 = 0;        // flush GPIO setup

        *UART0_ICR = 0x7FF;    // clear interrupts
        *UART0_IBRD = 2;       // 115200 baud
        *UART0_FBRD = 11;
        *UART0_LCRH = 7 << 4;  // 8n1, enable FIFOs
        *UART0_CR = 0x301;     // enable Tx, Rx, UART
    }

    nil wait() { do asm volatile("nop"); while (*UART0_FR & 32); }

    nil putc(u32 c) { wait(); *UART0_DR = c; }

    u8 getc() { return *UART0_DR; }

    nil puts(u8 *s) { while(*s) putc(*s++); }

    nil puts(const char *s) { while(*s) putc(*s++); }

    nil hex(u32 d) { for (i32 c = 28; c >= 0; c -= 4) putc((d >> c) & 15 + HEX((d >> c) & 15)); }

    nil dump(nil *ptr) {
        for (u64 a = (u64)ptr; a < (u64)ptr + 512; a += 16) {
            hex(a);
            puts(": ");

            for (u64 b = 0; b < 16; b++) {
                u8 c = *((u8*)(a + b));
                u64 d = (u32)c;
                d >>= 4;
                d &= 15;
                d += HEX(d);
                putc(d);
                d = (u32)c;
                d &= 15;
                d += HEX(d);
                putc(d);
                putc(' ');
                if (b % 4 == 3) putc(' ');
            }

            for (u64 b = 0; b < 16; b++) putc(*((u8*)(a + b)) < 32 || *((u8*)(a + b)) >= 127 ? '.' : *((u8*)(a + b)));

            putc('\n');
        }
    }
};

#endif
