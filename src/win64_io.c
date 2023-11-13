#include "nami/core.h"

#if defined(NM_PLATFORM_WINDOWS)
#define WIN32_LEAN_AND_MEAN

#include "windows.h"
#include "nami/string.h"

#define STDOUT_HANDLE_CHECK() \
if (!s_stdout_handle) s_stdout_handle = GetStdHandle(STD_OUTPUT_HANDLE)

static HANDLE s_stdout_handle = nm_nullptr;

void nm_print (const c8* str)
{
    STDOUT_HANDLE_CHECK();
    WriteConsoleA(s_stdout_handle, str, nm_cstr_len(str), nm_nullptr, nm_nullptr);
}

void nm_printf (const c8* fmt, ...)
{
    STDOUT_HANDLE_CHECK();

    c8 buffer[2000] = {0};

    nm_va_list   vargs;
    nm_va_start  (vargs, fmt);

    //TODO: create formatted string

    nm_va_end(vargs);
}

#endif // NM_PLATFORM_WINDOWS