#include "nami/string.h"
#include "nami/memory.h"
#include "nami/math.h"
#include "nami/io.h"

u64 nm_cstr_len (const c8* cstr)
{
    u64 len = 0;
    while (cstr[len] != 0) len ++;
    return len;
}

void nm_i64_to_cstr (c8* dest, i64 num)
{
    u64 ndigit = nm_i64_count(num);

    if (num < 0)
    {
        num = nm_math_abs(num);
        ndigit += 1;
    }

    dest[ndigit] = 0;

    if (num == 0)
    {
        dest[0] = '0';
        return;
    }

    while (num > 0)
    {
        dest[ndigit-1] = num%10 + 0x30;
        num /= 10;
        ndigit --;
    }

    if (ndigit == 1) dest[0] = '-';
}

void nm_cstr_copy (c8* dest, const c8* src)
{
    nm_mem_copy(dest, src, nm_cstr_len(src));
}

c8* nm_cstr_append (c8* dest, const c8* src)
{
    u64 dest_len = nm_cstr_len(dest);
    u64 src_len  = nm_cstr_len(src);
    nm_mem_copy(dest + dest_len, src, src_len);

    return dest;
}

c8* nm_cstr_format (c8* dest, const c8* fmt, ...)
{
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

                    nm_mem_copy(dest + offset, arg_str, arg_str_count);

                    offset += arg_str_count;
                    i++;

                    continue;
                }

                case 'd':
                {
                    i64 arg_num = nm_va_arg(vargs, int);
                    u64 arg_num_count = nm_i64_count(arg_num);

                    if (arg_num < 1) arg_num_count ++;

                    nm_i64_to_cstr(dest + offset, arg_num);

                    offset += arg_num_count;
                    i++;

                    continue;
                }
            }
        }

        dest[offset] = ch;
        offset ++;
    }

    nm_va_end(vargs);
    return dest;
}