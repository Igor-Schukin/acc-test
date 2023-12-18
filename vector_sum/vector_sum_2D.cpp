#include <cstddef>
#include <cstdio>
#include <cstdio>
#include "definitions.h"

res_type vector_sum(const size_t size, type* __restrict__ a)
{
    size_t blockCount = size / BLOCK_SIZE;

    res_type sum = 0;
    #pragma acc parallel loop reduction(+:sum)
    for (size_t block = 0; block < blockCount; block++) {
        res_type sumBlock = 0;
        #pragma acc loop reduction(+:sumBlock)
        for (size_t i = block * BLOCK_SIZE; i < (block + 1) * BLOCK_SIZE; i++) 
            sumBlock += a[i];
        sum += sumBlock;
    }

    return sum;
}