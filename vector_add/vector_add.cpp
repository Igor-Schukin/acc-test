#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <openacc.h>
#include <chrono>
#include "definitions.h"

extern type vector_add(
    size_t size,
    type* __restrict__ a,
    type* __restrict__ b,
    type* __restrict__ c
);

const size_t MAX_COUNT = 0x1FFFFFFFF / sizeof(type);

int main(int argc, char *argv[])
{
    setlocale(LC_NUMERIC, "");

    //~~~ Define vector size

    size_t size = MAX_COUNT;
    if (argc > 1) size = std::stoull(argv[1]);
    size = (size / BLOCK_SIZE) * BLOCK_SIZE;

    printf("vector size: %'ld\n", size);

    //~~~ ACC payload

    type* __restrict__ a = new type[size];
    for (size_t i = 0; i < size; i++) a[i] = i;

    type* __restrict__ b = new type[size];
    for (size_t i = 0; i < size; i++) b[i] = -i;

    type* __restrict__ c = new type[size];

    auto start = std::chrono::system_clock::now();

    //~~~ Include payload circles

    type max = vector_add(size, a, b, c);

    printf("error: %d\n", max); // for type = int

    //~~~ end of ACC payload

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    printf("elapsed time %'lu ms\n", elapsed);

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}