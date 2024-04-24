/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 */

#include <types.hpp>
#include <cpu.hpp>
#include <fb.hpp>
#include <mmu.hpp>

nomangle
void _start(void *bootinfo) {
    void *pages = mmu::palloc(10);  // allocate 10 blocks (1 block = 16 bytes)
    mmu::pfree(pages, 10);  // free 10 blocks
    fb::teletype::init();
    fb::teletype::putString("\e02mHello, World!\e07m");
    halt();
}
