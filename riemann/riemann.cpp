#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <openacc.h>
#include <chrono>
#include "definitions.h"

extern float riemannTest(const size_t intervals);

const size_t DEFAULT_INTERVALS = 1000000;

int main(int argc, char *argv[])
{
    setlocale(LC_NUMERIC, "");
    srand(time(NULL));
    rand();

    //~~~ Determinate matrix size

    size_t intervals = DEFAULT_INTERVALS;
    if (argc > 1) intervals = std::stoull(argv[1]);

    printf("subintervals number: %'d\n", intervals);

    auto start = std::chrono::system_clock::now();

    //~~~ ACC payload

    printf("Error = %.10f\n", riemannTest(intervals));

    //~~~ end of ACC payload

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    printf("elapsed time %'d ms\n", elapsed);

    return 0;
}