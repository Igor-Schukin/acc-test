#include <cstddef>
#include "definitions.h"

type vector_add(const size_t size, type* __restrict__ a, type* __restrict__ b, type* __restrict__ c)
{
    for (size_t i = 0; i < size; i++) c[i] = a[i] + b[i];
    type max = c[0];
    for (size_t i = 1; i < size; i++) if (c[i] > max) max = c[i];
    return max;
}