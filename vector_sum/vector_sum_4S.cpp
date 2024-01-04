#include <cstddef>
#include <cstdio>
#include "definitions.h"

res_type vector_sum(const size_t size, type* __restrict__ a)
{
    res_type sum = 0;
    #pragma acc data copy(a[0:size])
    {
        #pragma acc parallel loop reduction(+:sum)
        for (size_t i = 0; i < size; i++) sum += a[i];
    }
    return sum;
}