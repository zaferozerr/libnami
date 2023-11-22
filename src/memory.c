#include "nami/memory.h"

void nm_mem_copy (void* dest, const void* src, u64 size)
{
    for (u64 i = 0; i < size; i++) ((c8*)dest)[i] = ((const c8*)src)[i];
}

void nm_mem_zero (void* dest, u64 size)
{
    for (u64 i = 0; i < size; i++) ((c8*)dest)[i] = 0x0;
}

void nm_mem_set (void* dest, c8 val, u64 size)
{
    for (u64 i = 0; i < size; i++) ((c8*)dest)[i] = val;
}