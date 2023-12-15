
#include <cstddef>
#include "definitions.h"

type vector_add(const size_t size, type* __restrict__ a, type* __restrict__ b, type* __restrict__ c)
{
    size_t blockCount = size / BLOCK_SIZE;

    type max;
    #pragma acc data copyin(a[0:size], b[0:size]) copyout(c[0:size, max])
    {
        #pragma acc parallel loop
        for (size_t block = 0; block < blockCount; block++) 
            #pragma acc loop
            for (size_t i = block * BLOCK_SIZE; i < (block + 1) * BLOCK_SIZE; i++) 
                c[i] = a[i] + b[i];

        type max = c[0];
        #pragma acc parallel loop reduction(max:max)
        for (size_t block = 0; block < blockCount; block++) {
            type blockMax = c[block * BLOCK_SIZE];
            #pragma acc loop reduction(max:blockMax)
            for (size_t i = block * BLOCK_SIZE + 1; i < (block + 1) * BLOCK_SIZE; i++)
                if (c[i] > blockMax) blockMax = c[i];
            if (blockMax > max) max = blockMax;
        }
    }
    return max;
}