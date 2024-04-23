/*
 * Copyright (c) 2024 Ivan Chetchasov <chetvano@gmail.com>. All rights reserved.
 * Use of this source code is governed by a Mozilla Public License 2.0
 * that can be found in the LICENSE file.
 * 
 * Framebuffer architecture specific definitions.
 */

#pragma once

#include <types.hpp>

namespace fb {
    static u16 width = 80;
    static u16 height = 25;
};

struct fbcharbuf {
    u8 *data;

    fbcharbuf(): data(nullptr) {};
    fbcharbuf(u8 *data): data(data) {};

    void setChar(u32 x, u32 y, u8 c) {
        data[y * fb::width + x] = c;
    }

    u8 getChar(u32 x, u32 y) {
        return data[y * fb::width + x];
    }

    void setColor(u32 x, u32 y, u16 c) {
        data[y * fb::width + x] = c;
    }

    u16 getColor(u32 x, u32 y) {
        return data[y * fb::width + x];
    }
};

namespace fb {
    static u32 *gfb;
    static fbcharbuf tfb((u8 *)0xb8000);

    void clear(void) {
        for (u32 y = 0; y < fb::height; y++) {
            for (u32 x = 0; x < fb::width; x++) {
                tfb.setChar(x, y, ' ');
                tfb.setColor(x, y, 0x07);
            }
        }
    };

    namespace teletype {
        static u16 cursor_x = 0;
        static u16 cursor_y = 0;

        static void init(void) {
            fb::clear();
            cursor_x = cursor_y = 0;
        };

        static void putChar(u8 c) {
            tfb.setChar(cursor_x, cursor_y, c);
            tfb.setColor(cursor_x, cursor_y, 0x07);
            cursor_x++;
            if (cursor_x >= fb::width) {
                cursor_x = 0;
                cursor_y++;
            }
        };

        static u8 read_int(const char *str) {
            // read decimal number from string
            u8 val = 0;
            while (*str >= '0' && *str <= '9') {
                val = val * 10 + (*str - '0');
                str++;
            }
            return val;
        }

        static void putString(const char *str) {
            for (; *str; str++) {
                if (*str == '\n') {
                    cursor_x = 0;
                    cursor_y++;
                } else if (*str == '\t')
                    cursor_x += 4 - (cursor_x % 4);
                else if (*str == '\r')
                    cursor_x = 0;
                else if (*str == '\b')
                    if (cursor_x > 0)
                        cursor_x--;
                else if (*str == '\a') {
                    cursor_x = 0;
                    cursor_y = 0;
                } else if (*str == '\e') {
                    // ANSI escape sequence
                    do {
                        u8 style = teletype::read_int(++str);
                        fb::tfb.setColor(cursor_x, cursor_y, style);
                    } while (*str == ';');
                    if (*str == 'm')
                        str++;
                    else putChar(*str++);
                }
                putChar(*str);
            }
        };

        static void write_int(u32 val, int radix = 10) {
            static const char alphabet[] = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZ";
            u8 level = 0;
            while (val / radix / level)
                level++;
            level--;
            while (level >= 0) {
                u8 digit = val / radix / level % radix;
                teletype::putChar(alphabet[digit]);
                level--;
            }
        };
    };
};
