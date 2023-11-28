#include <cstddef>
#include <valarray>

void vector_add(const size_t size, int* __restrict__ a, int* __restrict__ b, int* __restrict__ c)
{
    std::valarray<int> va(size), vb(size);

    for (size_t i = 0; i < size; i++) va[i] = 2 * i; 

    for (size_t i = 0; i < size; i++) vb[i] = 10 * i;

    auto vc = va + vb;

    for (int i = 0; i < size; ++i) c[i] = vc[i];
}