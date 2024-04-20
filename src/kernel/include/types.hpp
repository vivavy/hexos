/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 */

#pragma once

#include <stdint.hpp>

#define offsetof(type, member) ((size_t) &((type *)0)->member)
#define offsetofinstance(type, instance, member) ((size_t) &((type *)instance)->member)
#define nomangle extern "C"
#define packed __attribute__((packed))
#define align(x) __attribute__((aligned(x)))

enum status {
    ok = 0,
    fail = 1
};
