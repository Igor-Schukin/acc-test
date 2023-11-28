#include <cstddef>
#include <cstdio>
#include <cstdio>

const size_t BLOCK_SIZE = 128;

void vector_sum(const size_t size, int* __restrict__ a)
{
    #pragma acc data
    {
        size_t blockCount = size / BLOCK_SIZE;

        #pragma acc parallel loop
        for (size_t block = 0; block < blockCount; block++) 
            #pragma acc loop
            for (size_t i = block * BLOCK_SIZE; i < (block + 1) * BLOCK_SIZE; i++) 
                a[i] = i; 

        unsigned long long int sum = 0;
        #pragma acc parallel loop reduction(+:sum)
        for (size_t block = 0; block < blockCount; block++) {
            unsigned long long int sumBlock = 0;
            #pragma acc loop reduction(+:sumBlock)
            for (size_t i = block * BLOCK_SIZE; i < (block + 1) * BLOCK_SIZE; i++) 
                sumBlock += a[i];
            sum += sumBlock;
        }

        printf("sum of elements: %llu\n", sum);
    }
}