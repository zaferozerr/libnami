// io related functions

#ifndef NAMI_IO_H
#define NAMI_IO_H

#include "core.h"

// Outputs a string buffer to STDOUT.
void nm_print (const c8* str);

// Outputs a formatted string buffer to STDOUT.
void nm_printf (const c8* fmt, ...);

#endif // NAMI_IO_H