/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 * 
 * MMU architecture specific definitions.
 */

#pragma once

#include <types.hpp>

extern uint endkernel;

// WARNING: WORKS ONLY WITH DISABLED MMU & PAE AND USING FLAT MODEL

namespace mmu {
    namespace bitmap {
        using bits = u64;
        static bits bitmap[1024];  // 1 bit from bitmap <-> 16 bytes from memory
    }

    void *palloc(uint size) {
        uint fcp, fbp, cc, bc = 0;  // fcp = first cluster pointer, fbp = first block pointer, cluster counter, block counter
        // cluster = 1024 bytes from memory = 64 blocks
        // block = 16 bytes from memory
        for (uint pi = 0; pi < 1024; pi++) {
            not_enough_size:
            for (uint bi = 0; bi < 64; bi++) {
                if (!(bitmap::bitmap[pi] & (1ULL << bi))) {
                    fcp = pi;
                    fbp = bi;
                    while (16 * (cc * 64 + bc) < size) {
                        bc++;
                        if (bc == 16) {
                            cc++;
                            bc = 0;
                        }
                        if (!(bitmap::bitmap[fcp+cc] & (1ULL << fbp+bc))) {
                            goto not_enough_size;
                        }
                    }
                    goto enough_size;
                }
            }
        }
        enough_size:
        for (uint pi = 0; pi < 1024; pi++) {
            bitmap::bitmap[pi] &= ~(1ULL << fbp);
        }
        return ((void *)(endkernel + fcp * 1024 + fbp * 16));
    };

    void pfree(void *ptr, uint size) {
        uint fcp, fbp, cc, bc = 0;
        // find clusters and blocks and unset their bits in bitmap
        for (uint pi = 0; pi < 1024; pi++) {
            for (uint bi = 0; bi < 64; bi++) {
                if ((bitmap::bitmap[pi] & (1ULL << bi)) && ((void *)(endkernel + fcp * 1024 + fbp * 16)) == ptr) {
                    bitmap::bitmap[pi] &= ~(1ULL << bi);
                    return;
                }
            }
        }
    };
};
