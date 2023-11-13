// container structures and related algorithm functions

#ifndef NAMI_CONTAINERS_H
#define NAMI_CONTAINERS_H

#include "core.h"

typedef struct nm_array_t
{
    u64 stride;
    u64 capacity;
    u64 size;
    void* data;
} nm_array_t;

#endif // NAMI_CONTAINERS_H