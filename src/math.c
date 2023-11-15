#include "nami/math.h"

i64 nm_math_abs (i64 val)
{
    return val * ((val>0) - (val<0));
}