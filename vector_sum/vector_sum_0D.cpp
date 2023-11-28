#include <cstddef>
#include <cstdio>
#include <cstdio>

const size_t BLOCK_SIZE = 128;

void vector_sum(const size_t size, int* __restrict__ a)
{
    size_t blockCount = size / BLOCK_SIZE;

    for (size_t block = 0; block < blockCount; block++) 
        for (size_t i = block * BLOCK_SIZE; i < (block + 1) * BLOCK_SIZE; i++) 
            a[i] = i; 

    unsigned long long int sum = 0;
    for (size_t block = 0; block < blockCount; block++) {
        unsigned long long int sumBlock = 0;
        for (size_t i = block * BLOCK_SIZE; i < (block + 1) * BLOCK_SIZE; i++) 
            sumBlock += a[i];
       sum += sumBlock;
    }

    printf("sum of elements: %llu\n", sum);
}