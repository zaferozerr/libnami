#include <nami/entry.h>
#include <nami/io.h>
#include <nami/string.h>
#include <nami/memory.h>

i32 nm_main ()
{
    c8* msg = nm_heap_alloc (12);
    
    nm_mem_copy (msg, "hello world", 11);
    nm_printf ("test: %s (%d)\n", msg, -42);

    nm_heap_free (msg);
    return 0;
}