#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <openacc.h>
#include <chrono>

#define type int

extern void vector_sum(
    size_t size,
    type* __restrict__ a
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

    auto start = std::chrono::system_clock::now();

    //~~~ Include payload circles

    vector_sum(vectorSize, a);

    //~~~ end of ACC payload

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    printf("elapsed time %'d ms\n", elapsed);

    delete[] a;

    return 0;
}