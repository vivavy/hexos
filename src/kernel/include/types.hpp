/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 */

#pragma once

#include <stdint.hpp>

#define NULL ((void *)0)
#define true -1
#define false 0
#define offsetof(type, member) ((size_t) &((type *)0)->member)
#define offsetofinstance(type, instance, member) ((size_t) &((type *)instance)->member)
#define in
#define out
#define nomangle extern "C"
#define ok 0
#define fail 1

typedef bool Bool;
typedef uint64_t uint;
typedef uint *pml4t_t;
