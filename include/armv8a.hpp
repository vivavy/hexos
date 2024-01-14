#ifndef __ARMV8A_WRAPPER__
#define __ARMV8A_WRAPPER__

#include <enhancecpp.hpp>

namespace armv8a {
    
    static u64 cpuid() {
        unsigned long long mpidr;
        asm volatile("mrs %0, mpidr_el1" : "=r"(mpidr));
        return mpidr & 0xff;
    }

    static void wfe() {
        asm volatile("wfe");
    }

    static void isb() {
        asm volatile("isb");
    }

    static void enable_irq() {
        asm volatile("msr daifclr, #0x2" ::: "memory");
    }

    static void disable_irq() {
        asm volatile("msr daifset, #0x2" ::: "memory");
    }

    static u64 get_el() {
        u64 el;
        asm volatile ("mrs %0, CurrentEL" : "=r" (el));
        return (el >> 2) & 3;
    }
};

#endif
