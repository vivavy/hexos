#ifndef __UART0DEV__
#define __UART0DEV__

#include <enhancecpp.hpp>
#include <gpio.hpp>
#include <mbox.hpp>

/* PL011 UART registers */
#define UART0_DR        ((volatile unsigned int*)(MMIO_BASE + 0x00201000))
#define UART0_FR        ((volatile unsigned int*)(MMIO_BASE + 0x00201018))
#define UART0_IBRD      ((volatile unsigned int*)(MMIO_BASE + 0x00201024))
#define UART0_FBRD      ((volatile unsigned int*)(MMIO_BASE + 0x00201028))
#define UART0_LCRH      ((volatile unsigned int*)(MMIO_BASE + 0x0020102C))
#define UART0_CR        ((volatile unsigned int*)(MMIO_BASE + 0x00201030))
#define UART0_IMSC      ((volatile unsigned int*)(MMIO_BASE + 0x00201038))
#define UART0_ICR       ((volatile unsigned int*)(MMIO_BASE + 0x00201044))

/**
 * Set baud rate and characteristics (115200 8N1) and map to GPIO
 */
namespace uart {
    void init() {
        register u32 r;

        // initialize UART
        *UART0_CR = 0;         // turn off UART0

        // set up clock for consistent divisor values
        mbox_buffer[0] = 9*4;
        mbox_buffer[1] = MBOX_REQUEST;
        mbox_buffer[2] = MBOX_TAG_SETCLKRATE; // set clock rate
        mbox_buffer[3] = 12;
        mbox_buffer[4] = 8;
        mbox_buffer[5] = 2;           // UART clock
        mbox_buffer[6] = 4000000;     // 4Mhz
        mbox_buffer[7] = 0;           // clear turbo
        mbox_buffer[8] = MBOX_TAG_LAST;
        
        mbox::call(MBOX_CH_PROP);

        // map UART0 to GPIO pins
        r = *GPFSEL1;
        r &= ~((7 << 12) | (7 << 15)); // gpio14, gpio15
        r |= (4 << 12) | (4 << 15);    // alt0
        *GPFSEL1 = r;
        *GPPUD = 0;            // enable pins 14 and 15
        r = 150;
        while(r--) {
            asm volatile("nop");
        }
        *GPPUDCLK0 = (1 << 14) | (1 << 15);
        r = 150;
        while (r--) {
            asm volatile("nop");
        }
        *GPPUDCLK0 = 0;        // flush GPIO setup

        *UART0_ICR = 0x7FF;    // clear interrupts
        *UART0_IBRD = 2;       // 115200 baud
        *UART0_FBRD = 0xB;
        *UART0_LCRH = 0x7 << 4;  // 8n1, enable FIFOs
        *UART0_CR = 0x301;     // enable Tx, Rx, UART
    }

    void wait() {
        do {
            asm volatile("nop");
        } while (*UART0_FR & 0x20);
    }

    void putc(u32 c) {
        /* wait until we can putc */
        wait();
        /* write the character to the buffer */
        *UART0_DR = c;
    }

    u8 getc() {
        u8 r;
        /* wait until something is in the buffer */
        wait();
        /* read it and return */
        r = (char)(*UART0_DR);
        /* convert carrige return to newline */
        return r == '\r' ? (u8)(*UART0_DR) : r;
    }

    void puts(u8 *s) {
        while(*s) {
            /* convert newline to carrige return + newline */
            if(*s == '\n')
                putc('\r');
            putc(*s++);
        }
    }

    void hex(u32 d) {
        u32 n;
        i32 c;
        for(c = 28; c >= 0; c -= 4) {
            // get highest tetrad
            n = (d >> c) & 0xF;
            // 0-9 => '0'-'9', 10-15 => 'A'-'F'
            n += n > 9 ? 0x37 : 0x30;
            putc(n);
        }
    }

    void dump(void *ptr)
    {
        u64 a, b, d;
        u8 c;

        for(a = (u64)ptr; a < (u64)ptr + 512; a += 16) {
            hex(a);
            puts((u8 *)": ");

            for(b = 0; b < 16; b++) {
                c = *((u8*)(a + b));
                d = (u32)c;
                d >>= 4;
                d &= 0xF;
                d += d > 9 ? 0x37 : 0x30;
                putc(d);
                d = (u32)c;
                d &= 0xF;
                d += d > 9 ? 0x37 : 0x30;
                putc(d);
                putc(' ');
                if(b % 4 == 3)
                    putc(' ');
            }

            for(b = 0; b < 16; b++) {
                c = *((u8*)(a + b));
                putc(c < 32 || c >= 127 ? '.' : c);
            }
            putc('\r');
            putc('\n');
        }
    }
};

#endif
