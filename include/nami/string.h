// string handling functions

#ifndef NAMI_STRING_H
#define NAMI_STRING_H

#include "core.h"

// Returns the size (bytes) of string, excluding null terminator.
u64  nm_cstr_len (const c8* cstr);

// Copies source string buffer into destination buffer.
void nm_cstr_copy (c8* dest, const c8* src);

// Appends the destination string with the source string.
c8* nm_cstr_append (c8* dest, const c8* src);

// Formats the desination string.
c8* nm_cstr_format (c8* dest, const c8* fmt, ...);

// converts a signed 64bit integer value into ascii representation.
void nm_i64_to_cstr (c8* dest, i64 num);

#endif // NAMI_STRING_H