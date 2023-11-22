#include "nami/io.h"
#include "nami/string.h"
#include "internals.h"

#if defined(NM_PLATFORM_POSIX)
#include <unistd.h>

void nm_print (const c8* str)
{
    write (STDOUT_FILENO, str, nm_cstr_len(str));
}

void nm_printf (const c8* fmt, ...)
{
   c8 buffer[2000] = {0};

    nm_va_list  vargs;
    nm_va_start (vargs, fmt);

    _nm_cstr_format_valist (buffer, fmt, vargs);
    
    nm_va_end (vargs);

    write (STDOUT_FILENO, buffer, nm_cstr_len(buffer));
}

#endif // NM_PLATFORM_POSIX