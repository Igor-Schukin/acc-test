#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <openacc.h>
#include <chrono>
#include "definitions.h"

extern res_type vector_sum(
    size_t size,
    type* __restrict__ a
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

    auto start = std::chrono::system_clock::now();

    //~~~ Include payload circles

    printf("error: %llu\n", vector_sum(size, a) - (size-1) * size / 2); // res_type = unsigned long long int

    //~~~ end of ACC payload

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    printf("elapsed time %'ld ms\n", elapsed);

    delete[] a;

    return 0;
}