// platform-specific entry points

#ifndef NAMI_ENTRY_H
#define NAMI_ENTRY_H

#include "core.h"

#if !defined(NAMI_BUILD_LIB)
extern i32 nm_main (void);
#   if defined(NM_PLATFORM_WINDOWS)
        i32 WinMain () { return nm_main(); }
#   elif defined(NM_PLATFORM_POSIX)
        i32 main () { return nm_main(); }
#   endif
#endif // !NAMI_BUILD_LIB

#endif // NAMI_ENTRY_H