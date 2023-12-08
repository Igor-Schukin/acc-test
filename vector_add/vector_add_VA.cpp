#include <cstddef>
#include <valarray>
#include "definitions.h"

type vector_add(const size_t size, type* __restrict__ a, type* __restrict__ b, type* __restrict__ c)
{
    std::valarray<type> va(a, size), vb(b, size);

    std::valarray<type> vc = va + vb;

    std::copy(begin(vc), end(vc), c);

    return vc.max();
}