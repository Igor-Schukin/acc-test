#include <cstddef>
#include <cstdio>
#include <valarray>
#include "definitions.h"

res_type vector_sum(const size_t size, type* __restrict__ a)
{
    std::valarray<type> va(size);
    for (size_t i = 0; i < size; i++) va[i] = a[i]; 
    res_type sum = va.sum();

    return sum;
}