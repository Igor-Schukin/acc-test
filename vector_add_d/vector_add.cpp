#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <openacc.h>
#include <chrono>

#define type int

extern void vector_add(
    size_t size,
    type* __restrict__ a,
    type* __restrict__ b,
    type* __restrict__ c
);

const size_t BLOCK_SIZE = 128;
const size_t MAX_BLOCK_COUNT = 0x1FFFFFFFF / sizeof(type) / BLOCK_SIZE;

int main(int argc, char *argv[])
{
    setlocale(LC_NUMERIC, "");

    //~~~ Determinate vector size: 0 - small, 1 - middle, 2 - maximum (default)

    size_t blockCount = MAX_BLOCK_COUNT;
    if (argc > 1) {
        int bs = std::stoull(argv[1]);
        if (bs == 0) blockCount = 100000;
        else if (bs == 1) blockCount = 10000000;
    }
    size_t vectorSize = blockCount * BLOCK_SIZE;

    printf("vector size: %'d\n", vectorSize);

    //~~~ ACC payload

    type* __restrict__ a = new type[vectorSize];
    type* __restrict__ b = new type[vectorSize];
    type* __restrict__ c = new type[vectorSize];

    auto start = std::chrono::system_clock::now();

    //~~~ Include payload circles

    vector_add(vectorSize, a, b, c);

    //~~~ end of ACC payload

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    printf("elapsed time %'d ms\n", elapsed);

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}