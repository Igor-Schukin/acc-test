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
    int count = 1;
    if (argc > 1) size = std::stoull(argv[1]);
    if (argc == 3) count = std::stoi(argv[2]);
    size = (size / BLOCK_SIZE) * BLOCK_SIZE;
    
    printf("vector size: %'ld\n", size);

    type* __restrict__ a = new type[size];
    for (size_t i = 0; i < size; i++) a[i] = i;
    res_type error = 0;

    printf("elapsed time (ms) ");

    for (int i = 0; i < count; i++) {
        //~~~ ACC payload

        auto start = std::chrono::system_clock::now();

        //~~~ Include payload circles

        res_type res = vector_sum(size, a) - (size-1) * size / 2;
        if (res > error) error = res;

        //~~~ end of ACC payload

        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        printf("%'ld ", elapsed);
    }

    printf("\nerror: %llu\n", error); // res_type = unsigned long long int

    delete[] a;

    return 0;
}