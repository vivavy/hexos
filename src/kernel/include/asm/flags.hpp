/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 * 
 * This file contains the flags definitions.
 */

#pragma once

#include <types.hpp>

/**
 * EFLAGS bits
 */
inline constexpr u32 X86_EFLAGS_CF	 = 0x00000001; /* Carry Flag */
inline constexpr u32 X86_EFLAGS_PF	 = 0x00000004; /* Parity Flag */
inline constexpr u32 X86_EFLAGS_AF	 = 0x00000010; /* Auxillary carry Flag */
inline constexpr u32 X86_EFLAGS_ZF	 = 0x00000040; /* Zero Flag */
inline constexpr u32 X86_EFLAGS_SF	 = 0x00000080; /* Sign Flag */
inline constexpr u32 X86_EFLAGS_TF	 = 0x00000100; /* Trap Flag */
inline constexpr u32 X86_EFLAGS_IF	 = 0x00000200; /* Interrupt Flag */
inline constexpr u32 X86_EFLAGS_DF	 = 0x00000400; /* Direction Flag */
inline constexpr u32 X86_EFLAGS_OF	 = 0x00000800; /* Overflow Flag */
inline constexpr u32 X86_EFLAGS_IOPL = 0x00003000; /* IOPL mask */
inline constexpr u32 X86_EFLAGS_NT	 = 0x00004000; /* Nested Task */
inline constexpr u32 X86_EFLAGS_RF	 = 0x00010000; /* Resume Flag */
inline constexpr u32 X86_EFLAGS_VM	 = 0x00020000; /* Virtual Mode */
inline constexpr u32 X86_EFLAGS_AC	 = 0x00040000; /* Alignment Check */
inline constexpr u32 X86_EFLAGS_VIF	 = 0x00080000; /* Virtual Interrupt Flag */
inline constexpr u32 X86_EFLAGS_VIP	 = 0x00100000; /* Virtual Interrupt Pending */
inline constexpr u32 X86_EFLAGS_ID	 = 0x00200000; /* CPUID detection flag */

/**
 * Basic CPU control in CR0
 */
inline constexpr u32 X86_CR0_PE	 = 0x00000001; /* Protection Enable */
inline constexpr u32 X86_CR0_MP	 = 0x00000002; /* Monitor Coprocessor */
inline constexpr u32 X86_CR0_EM	 = 0x00000004; /* Emulation */
inline constexpr u32 X86_CR0_TS	 = 0x00000008; /* Task Switched */
inline constexpr u32 X86_CR0_ET	 = 0x00000010; /* Extension Type */
inline constexpr u32 X86_CR0_NE	 = 0x00000020; /* Numeric Error */
inline constexpr u32 X86_CR0_WP	 = 0x00010000; /* Write Protect */
inline constexpr u32 X86_CR0_AM	 = 0x00040000; /* Alignment Mask */
inline constexpr u32 X86_CR0_NW	 = 0x20000000; /* Not Write-through */
inline constexpr u32 X86_CR0_CD	 = 0x40000000; /* Cache Disable */
inline constexpr u32 X86_CR0_PG	 = 0x80000000; /* Paging */

/**
 * Paging options in CR3
 */
inline constexpr u32 X86_CR3_PWT	 = 0x00000008; /* Page Write Through */
inline constexpr u32 X86_CR3_PCD	 = 0x00000010; /* Page Cache Disable */

/**
 * Intel CPU features in CR4
 */
inline constexpr u32 X86_CR4_VME	    = 0x00000001; /* enable vm86 extensions */
inline constexpr u32 X86_CR4_PVI	    = 0x00000002; /* virtual interrupts flag enable */
inline constexpr u32 X86_CR4_TSD	    = 0x00000004; /* disable time stamp at ipl 3 */
inline constexpr u32 X86_CR4_DE	        = 0x00000008; /* enable debugging extensions */
inline constexpr u32 X86_CR4_PSE	    = 0x00000010; /* enable page size extensions */
inline constexpr u32 X86_CR4_PAE	    = 0x00000020; /* enable physical address extensions */
inline constexpr u32 X86_CR4_MCE	    = 0x00000040; /* Machine check enable */
inline constexpr u32 X86_CR4_PGE	    = 0x00000080; /* enable global pages */
inline constexpr u32 X86_CR4_PCE	    = 0x00000100; /* enable performance counters at ipl 3 */
inline constexpr u32 X86_CR4_OSFXSR	    = 0x00000200; /* enable fast FPU save and restore */
inline constexpr u32 X86_CR4_OSXMMEXCPT = 0x00000400; /* enable unmasked SSE exceptions */
inline constexpr u32 X86_CR4_VMXE	    = 0x00002000; /* enable VMX virtualization */
inline constexpr u32 X86_CR4_OSXSAVE    = 0x00000400; /* enable xsave and xrestore */

/*
 * PTE/PMD flags
 */
inline constexpr u32 MMU_PAGE_PRESENT        = 1UL;
inline constexpr u32 MMU_PAGE_WRITABLE       = 1UL << 1;
inline constexpr u32 MMU_PAGE_USERMODE       = 1UL << 2;
inline constexpr u32 MMU_PAGE_DISABLE_CACHE  = 1UL << 4;
inline constexpr u32 MMU_PAGE_4MB            = 1UL << 7;
