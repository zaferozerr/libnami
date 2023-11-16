// core library macros and defines

#ifndef NAMI_CORE_H
#define NAMI_CORE_H

#if defined(__cplusplus)
extern "C" {
#endif // __cplusplus

#if defined(_WIN64)
#   define NM_PLATFORM_WINDOWS
#elif defined(__linux__)
#   define NM_PLATFORM_LINUX
#   define NM_PLATFORM_POSIX
#elif defined(__APPLE__)
#   include <TargetConditionals.h>
#   define NM_PLATFORM_APPLE
#   define NM_PLATFORM_POSIX
#endif

#if defined(__aarch64__)
#   define NM_ARCH_ARM64
#elif defined(__amd64__)
#   define NM_ARCH_X64
#endif

#define NM_STATIC_ASSERT(expr, msg) _Static_assert(expr, msg)
#define nm_nullptr ((void*)0x0)

#define nm_va_list   __builtin_va_list
#define nm_va_start  __builtin_va_start
#define nm_va_end    __builtin_va_end
#define nm_va_arg    __builtin_va_arg

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef signed char      i8;
typedef signed short     i16;
typedef signed int       i32;
typedef signed long long i64;

typedef char   c8;
typedef float  f32;
typedef double f64;

NM_STATIC_ASSERT(sizeof(u8)  == 1, "u8 expected to be 1 byte(s)");
NM_STATIC_ASSERT(sizeof(u16) == 2, "u16 expected to be 2 byte(s)");
NM_STATIC_ASSERT(sizeof(u32) == 4, "u32 expected to be 4 byte(s)");
NM_STATIC_ASSERT(sizeof(u64) == 8, "u64 expected to be 8 byte(s)");

NM_STATIC_ASSERT(sizeof(i8)  == 1, "i8  expected to be 1 byte(s)");
NM_STATIC_ASSERT(sizeof(i16) == 2, "i16 expected to be 2 byte(s)");
NM_STATIC_ASSERT(sizeof(i32) == 4, "i32 expected to be 4 byte(s)");
NM_STATIC_ASSERT(sizeof(i64) == 8, "i64 expected to be 8 byte(s)");

NM_STATIC_ASSERT(sizeof(c8)  == 1, "c8 expected to be 1 byte(s)");
NM_STATIC_ASSERT(sizeof(f32) == 4, "f32 expected to be 4 byte(s)");
NM_STATIC_ASSERT(sizeof(f64) == 8, "f64 expected to be 8 byte(s)");

u64 nm_i64_count (i64 val);

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // NAMI_CORE_H