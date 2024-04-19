/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 */

#include <types.hpp>
#include <platform.hpp>
#include <mmu.hpp>

nomangle
void _start(pml4t_t pml4t_) {
    PML4T = pml4t_;
    halt();
}
