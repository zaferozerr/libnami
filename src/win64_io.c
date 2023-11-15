#include "nami/core.h"
#include "nami/memory.h"
#include "nami/math.h"

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

    c8  buffer[2000] = {0};
    u64 offset = 0;

    nm_va_list   vargs;
    nm_va_start  (vargs, fmt);

    for (u64 i = 0; fmt[i] != 0; i++)
    {
        c8 ch = fmt[i];

        if (ch == '%' && fmt[i+1] != 0)
        {
            switch (fmt[i+1])
            {
                case 's':
                {
                    const c8* arg_str = nm_va_arg(vargs, const c8*);
                    u64 arg_str_count = nm_cstr_len(arg_str);

                    nm_mem_copy(buffer + offset, arg_str, arg_str_count);

                    offset += arg_str_count;
                    i++;

                    continue;
                }

                case 'd':
                {
                    i64 arg_num = nm_va_arg(vargs, int);
                    u64 arg_num_count = nm_i64_count(arg_num);

                    if (arg_num < 1) arg_num_count ++;

                    nm_i64_to_cstr(buffer + offset, arg_num);

                    offset += arg_num_count;
                    i++;

                    continue;
                }
            }
        }

        buffer[offset] = ch;
        offset ++;
    }

    nm_va_end(vargs);
    nm_print(buffer);
}

#endif // NM_PLATFORM_WINDOWS