#ifndef __TIME_WRAPPER__
#define __TIME_WRAPPER__

#include <gpio.hpp>
#include <cppdlc.hpp>

#define SYSTMR_LO        ((volatile unsigned int*)(MMIO_BASE + 0x00003004))
#define SYSTMR_HI        ((volatile unsigned int*)(MMIO_BASE + 0x00003008))

namespace time {

    void wait_cycles(u32 n) {
        if (n)
            while (n--)
                asm volatile ("nop");
    }

    void sleep(u32 mcs) {
        register u64 f, t, r;
        // get the current counter frequency
        asm volatile ("mrs %0, cntfrq_el0" : "=r"(f));
        // read the current counter
        asm volatile ("mrs %0, cntpct_el0" : "=r"(t));
        // calculate required count increase
        u64 i = ((f / 1000) * mcs) / 1000;
        // loop while counter increase is less than i
        do {
            asm volatile ("mrs %0, cntpct_el0" : "=r"(r));
        } while (r - t < i);
    }

    u64 get_uptime() {
        u32 h = -1, l;
        // we must read MMIO area as two separate 32 bit reads
        h = *SYSTMR_HI;
        l = *SYSTMR_LO;
        // we have to repeat it if high word changed during read
        if (h != *SYSTMR_HI) {
            h = *SYSTMR_HI;
            l = *SYSTMR_LO;
        }
        // compose long int value
        return ((u64) h << 32) | l;
    }

};

#endif
