/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 */

#pragma once

#include <stdint.hpp>

#define offsetof(type, member) ((u64) &((type *)0)->member)
#define offsetofinstance(type, instance, member) ((u64) &((type *)instance)->member)
#define nomangle extern "C"
#define TYPE(orig, type) typedef orig _v_##type; using type = _v_##type

TYPE(u64 *, pml4t);
TYPE(const char *, cchar);

enum status {
    ok = 0,
    fail = 1
};
