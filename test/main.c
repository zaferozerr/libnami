#include <nami/entry.h>
#include <nami/io.h>
#include <nami/string.h>
#include <nami/memory.h>

i32 nm_main ()
{
    c8* msg = nm_heap_alloc (16377);

    //nm_heap_resize (msg, 16378);

    nm_mem_copy (msg, "hello world", 16377);
    //nm_mem_set (msg, 0x30, 1990);

    nm_printf ("test: %s (%d)\n", msg, -42);

    nm_heap_free (msg);
    return 0;
}