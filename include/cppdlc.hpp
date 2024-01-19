#ifndef __STDINT_HPP__
#define __STDINT_HPP__

#define nomangle extern "C"
#define false 0
#define true -1
#define null false
#define none null
#define nil void
#define skip volatile
#define reg register
#define HEX(d) (d > 9 ? 'A' : '0')

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int64_t;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef u8 byte;
typedef u16 word;
typedef u32 dword;
typedef u64 qword;

typedef u8 db;
typedef u16 dw;
typedef u32 dd;
typedef u64 dq;

#endif
