#ifndef __ARMV8A_WRAPPER__
#define __ARMV8A_WRAPPER__

#include <cppdlc.hpp>

namespace armv8a {
    
    static u64 cpuid() {
        unsigned long long mpidr;
        asm skip ("mrs %0, mpidr_el1" : "=r"(mpidr));
        return mpidr & 255;
    }

    static nil wfe() { asm skip ("wfe"); }

    static nil isb() { asm skip ("isb"); }

    static nil enable_irq() { asm skip("msr daifclr, #0x2" ::: "memory"); }

    static nil disable_irq() { asm skip("msr daifset, #0x2" ::: "memory"); }

    static u64 get_el() {
        u64 el;
        asm skip ("mrs %0, CurrentEL" : "=r" (el));
        return (el >> 2) & 3;
    }
};

#endif
