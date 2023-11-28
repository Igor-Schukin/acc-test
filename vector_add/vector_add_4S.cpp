#include <cstddef>

void vector_add(const size_t size, int* __restrict__ a, int* __restrict__ b, int* __restrict__ c)
{
    #pragma acc data create(a[0:size], b[0:size]) copyout(c[0:size])
    {
        #pragma acc parallel loop
        for (size_t i = 0; i < size; i++) a[i] = 2 * i; 

        #pragma acc parallel loop
        for (size_t i = 0; i < size; i++) b[i] = 10 * i;

        #pragma acc parallel loop
        for (size_t i = 0; i < size; i++) c[i] = a[i] + b[i];
    }
}