#include <cstddef>
#include <cstdio>

void vector_sum(const size_t size, int* __restrict__ a)
{
    #pragma acc data
    {
        #pragma acc parallel loop
        for (size_t i = 0; i < size; i++) a[i] = i; 

        unsigned long long int sum = 0;
        #pragma acc parallel loop reduction(+:sum)
        for (size_t i = 0; i < size; i++) sum += a[i];

        printf("sum of elements: %llu\n", sum);
    }
}