#include <cstddef>

const size_t BLOCK_SIZE = 128;

void vector_add(const size_t size, int* __restrict__ a, int* __restrict__ b, int* __restrict__ c)
{
    size_t blockCount = size / BLOCK_SIZE;

    for (size_t block = 0; block < blockCount; block++) 
        for (size_t i = block * BLOCK_SIZE; i < (block + 1) * BLOCK_SIZE; i++) 
            a[i] = 2 * i; 

    for (size_t block = 0; block < blockCount; block++) 
        for (size_t i = block * BLOCK_SIZE; i < (block + 1) * BLOCK_SIZE; i++) 
            b[i] = 10 * i; 

    for (size_t block = 0; block < blockCount; block++) 
        for (size_t i = block * BLOCK_SIZE; i < (block + 1) * BLOCK_SIZE; i++) 
           c[i] = a[i] + b[i];
}