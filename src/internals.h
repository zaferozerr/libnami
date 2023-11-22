#ifndef NAMI_INTERNALS_H
#define NAMI_INTERNALS_H

#include "nami/core.h"

// Formats the destination buffer using a va_list.
c8* _nm_cstr_format_valist (c8* dest, const c8* fmt, nm_va_list vargs);

#endif // NAMI_INTERNALS_H