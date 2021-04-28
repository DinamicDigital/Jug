#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define ELEMENTS(x) (sizeof(x) / sizeof(x[0]))
#define FMT_BOOL(x) (x ? "true" : "false")

#define true 1
#define false 0

typedef uint8_t  u8;
typedef int8_t   s8;
typedef uint16_t u16;
typedef int16_t  s16;
typedef uint32_t u32;
typedef int32_t  s32;
typedef uint64_t u64;
typedef int64_t  s64;

typedef float f32;
typedef double f64;

typedef struct _S_String {
    char* str;
    size_t size;
} String;
