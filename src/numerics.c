#include "nami/core.h"
#include "nami/math.h"

u64 nm_i64_count (i64 val)
{
    val = nm_math_abs (val);
    u64 ndigit = 0x0;

    while (val > 0)
    {
        ndigit ++;
        val /= 10;
    }

    return ndigit;
}