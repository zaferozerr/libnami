// string handling functions

#ifndef NAMI_STRING_H
#define NAMI_STRING_H

#include "core.h"

u64  nm_cstr_len    (const c8* cstr);
void nm_i64_to_cstr (c8* dest, i64 num);
void nm_cstr_copy   (c8* dest, const c8* src);
c8*  nm_cstr_append (c8* dest, const c8* src);
c8*  nm_cstr_format (c8* dest, const c8* fmt, ...);

#endif // NAMI_STRING_H