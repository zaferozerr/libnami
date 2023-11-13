#include "nami/string.h"

u64 nm_cstr_len (const c8* cstr)
{
    u64 len = 0;
    c8 ch = cstr[0];

    while (ch != 0)
    {
        len ++;
        ch = cstr[len];
    }

    return len;
}

void nm_int_to_cstr (c8* dest, u64 num)
{
    
}