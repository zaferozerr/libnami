#include <nami/entry.h>
#include <nami/io.h>
#include <nami/string.h>

i32 nm_main ()
{
    nm_printf("test: %s (%d)\n", "hello world", 42);
    return 0;
}