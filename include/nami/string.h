// string handling functions

#ifndef NAMI_STRING_H
#define NAMI_STRING_H

#include "core.h"

u64 nm_cstr_len (const c8* cstr);

void nm_u64_to_cstr (c8* dest, u64 num);

#endif // NAMI_STRING_H