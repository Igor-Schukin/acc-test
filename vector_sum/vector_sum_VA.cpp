#include <cstddef>
#include <cstdio>
#include <valarray>

void vector_sum(const size_t size, int* __restrict__ a)
{

    std::valarray<int> va(size);

    for (size_t i = 0; i < size; i++) va[i] = i; 

    unsigned long long int sum = va.sum();

    printf("sum of elements: %llu\n", sum);
}