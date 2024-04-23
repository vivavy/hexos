/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 */

#include <types.hpp>
#include <cpu.hpp>
#include <fb.hpp>

nomangle
void _start(void *bootinfo) {
    fb::teletype::init();
    fb::teletype::putString("\e02mHello, World!\e07m");
    halt();
}
