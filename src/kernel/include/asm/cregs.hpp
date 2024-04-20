/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 * 
 * This file contains the control registers definitions.
 */

#pragma once

#include <types.hpp>

static inline void set_cr3(uint32_t pagedir) {
	asm ("mov %0, %%cr3": :"r" (pagedir));
}

static inline uint32_t get_cr3(void) {
	uint32_t _cr3;
	asm ("mov %%cr3, %0":"=r" (_cr3));
	return _cr3;
}

static inline void set_cr0(uint32_t val) {
	asm ("mov %0, %%cr0" : :"r" (val));
}

static inline uint32_t get_cr0(void) {
	uint32_t _cr0;
	asm ("mov %%cr0, %0":"=r" (_cr0));
	return _cr0;
}

static inline void set_cr4(uint32_t val) {
	asm ("mov %0, %%cr4" : :"r" (val));
}

static inline uint32_t get_cr4(void) {
	uint32_t _cr4;
	asm ("mov %%cr2, %0":"=r" (_cr4):);
	return _cr4;
}


static inline uint32_t get_cr2(void) {
	uint32_t _cr2;

	asm ("mov %%cr2, %0":"=r" (_cr2):);
	return _cr2;
}
