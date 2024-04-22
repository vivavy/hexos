/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 * 
 * This file contains the MMU definitions.
 */

#pragma once

#include <types.hpp>
#include <asm/flags.hpp>
#include <asm/cregs.hpp>

//                          WARNING: ONLY FOR x86_64 for now!
using uintptr_t = u64 *;
using paddr_t = uintptr_t;
using vaddr_t = uintptr_t;

// TLB - Translation Lookaside Buffer
// TLBR - Translation Lookaside Buffer Record
struct tlbr {
    paddr_t paddr;  // physical address
    vaddr_t vaddr;  // virtual address
    u64 flags;      // flags
};

// TLBRT - Translation Lookaside Buffer Record Table (same as TLB)
using tlbrt = struct tlbr *;

namespace mmu {
    namespace tlb {
        inline void flush(vaddr_t addr = nullptr) {
            if (addr == (vaddr_t)-1) set_cr3(get_cr3());
            else asm volatile("invlpg (%0)" ::"r" (addr) : "memory");
        }
    }
    inline void enable() {
        set_cr0(get_cr0() | X86_CR0_PG | X86_CR0_WP);
    }
    inline void disable() {
        set_cr0(get_cr0() & ~(X86_CR0_PG));
    }
    inline vaddr_t get_fault_addr() {
        return (vaddr_t)(u64)get_cr2();
    }
}
