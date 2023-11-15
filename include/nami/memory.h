// memory allocation and handling functions

#ifndef NAMI_MEMORY_H
#define NAMI_MEMORY_H

#include "core.h"

#define nm_stack_alloc(size) __builtin_alloca(size)

void nm_mem_copy (void* dest, const void* src, u64 count);

#endif // NAMI_MEMORY_H