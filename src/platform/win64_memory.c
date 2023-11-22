#include "nami/memory.h"

#if defined(NM_PLATFORM_WINDOWS)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

static HANDLE s_heap_handle = nm_nullptr;

#define HEAP_HANDLE_CHECK() \
if (!s_heap_handle) s_heap_handle = GetProcessHeap()

void* nm_heap_alloc (u64 size)
{
    HEAP_HANDLE_CHECK ();
    return HeapAlloc (s_heap_handle, HEAP_ZERO_MEMORY, size);
}

void* nm_heap_resize (void* ptr, u64 size)
{
    HEAP_HANDLE_CHECK ();
    return HeapReAlloc (s_heap_handle, HEAP_ZERO_MEMORY, size);
}

void nm_heap_free (void* ptr)
{
    HEAP_HANDLE_CHECK ();
    HeapFree (s_heap_handle, 0x0, ptr);
}


#endif // NM_PLATFORM_WINDOWS