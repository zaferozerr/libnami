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
        dest[0] == '0';
        return;
    }

    while (num > 0)
    {
        dest[ndigit-1] = num%10 + '0';
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
    //TODO: implement cstr_append
}