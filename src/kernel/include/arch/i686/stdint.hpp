/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 */

#pragma once

using int8_t = signed char;
using uint8_t = unsigned char;
using int16_t = signed short;
using uint16_t = unsigned short;
using int32_t = signed int;
using uint32_t = unsigned int;
using int64_t = signed long long;
using uint64_t = unsigned long long;

using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

using ib = i8;
using db = u8;
using iw = i16;
using dw = u16;
using id = i32;
using dd = u32;
using iq = i64;
using dq = u64;

using int8 = i8;
using uint8 = u8;
using int16 = i16;
using uint16 = u16;
using int32 = i32;
using uint32 = u32;
using int64 = i64;
using uint64 = u64;

using uint = u32;

#define int i32

using size_t = uint;

inline constexpr uint INT_MAX = ((uint)(-1LL));

#define ARCH "i686"

namespace arch {
    inline const char *name = ARCH;
    inline const u8 bitness = 64;
    inline const char *family = "x86";
    inline const char *prodname = "IA-32";
}

