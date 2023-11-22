#include <nami/memory.h>

#if defined(NM_PLATFORM_POSIX)
#include <unistd.h>
#include <sys/mman.h>

#include <nami/io.h>

#define MEM_HEADER_SIZE (sizeof(u64))

void* nm_heap_alloc (u64 size)
{
    if (size == 0) return nm_nullptr;

    void* ptr = mmap (nm_nullptr, MEM_HEADER_SIZE + size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (!ptr) return nm_nullptr;

    ((u64*)ptr)[0] = size;

    return (ptr + MEM_HEADER_SIZE);
}

void* nm_heap_resize (void* ptr, u64 size)
{
    void* mem_ptr  = ptr - MEM_HEADER_SIZE;
    u64   old_size = ((u64*)(mem_ptr))[0];

    if (size > old_size)
    {
        void* new_ptr = mmap (mem_ptr, MEM_HEADER_SIZE + size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
        if (!new_ptr) return nm_nullptr;

        ((u64*)(new_ptr))[0] = size;

        if (new_ptr != mem_ptr)
        {
            nm_mem_copy (new_ptr + MEM_HEADER_SIZE, ptr, size);
            munmap (mem_ptr, old_size);
            nm_printf("old addr: %d, new: %d", mem_ptr, new_ptr);
        }

        else
        {
            nm_print("addr same\n");
        }

        return new_ptr + MEM_HEADER_SIZE;
    }

    else if (size < old_size)
    {
        u64 diff_size = old_size - size;
        munmap (ptr, diff_size);
        ((u64*)(mem_ptr))[0] = size;

        return ptr;
    }

    else if (size == 0)
    {
        nm_heap_free (ptr);
        return nm_nullptr;
    }

    else if (size == old_size) return ptr;

    return nm_nullptr;
}

void nm_heap_free (void* ptr)
{
    void* mem_ptr  = ptr - MEM_HEADER_SIZE;
    u64   ptr_size = ((u64*)(mem_ptr))[0] + MEM_HEADER_SIZE;

    munmap (mem_ptr, ptr_size);
}

#endif // NM_PLATFORM_POSIX