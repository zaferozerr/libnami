#include "nami/memory.h"

void nm_mem_copy (void* dest, const void* src, u64 count)
{
    for (u64 i = 0; i < count; i++)
    {
        ((c8*)dest)[i] = ((const c8*)src)[i];
    }
}