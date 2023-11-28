#include <cstddef>

void vector_add(const size_t size, int* __restrict__ a, int* __restrict__ b, int* __restrict__ c)
{
    for (size_t i = 0; i < size; i++) a[i] = 2 * i; 
    for (size_t i = 0; i < size; i++) b[i] = 10 * i;

    for (size_t i = 0; i < size; i++) c[i] = a[i] + b[i];
}