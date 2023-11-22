// memory allocation and handling functions

#ifndef NAMI_MEMORY_H
#define NAMI_MEMORY_H

#include "core.h"

// Copies N bytes from source buffer into destination buffer.
void nm_mem_copy (void* dest, const void* src, u64 size);

// Copies N 0x00 bytes into destination buffer.
void nm_mem_zero (void* dest, u64 size);

// Copies N bytes of value into destination buffer.
void nm_mem_set (void* dest, c8 val, u64 size);

// Allocates a memory region on the stack.
#define nm_stack_alloc(size) __builtin_alloca(size)

// Allocates a memory region on the heap.
void* nm_heap_alloc (u64 size);

// Resizes a previously heap allocated memory region;
void* nm_heap_resize (void* ptr, u64 size);

// Frees a previously heap allocated memory region.
void nm_heap_free (void* ptr);

#endif // NAMI_MEMORY_H