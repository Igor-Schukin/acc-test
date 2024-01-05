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
    int count = 1;
    if (argc > 1) intervals = std::stoull(argv[1]);
    if (argc == 3) count = std::stoi(argv[2]);

    printf("subintervals number: %'ld\n", intervals);
    printf("elapsed time, ms: ");
    float error = 0;

    for (int i = 0; i < count; i++) {

        auto start = std::chrono::system_clock::now();

        //~~~ ACC payload

        float res = riemannTest(intervals);
        if (res > error) error = res;

        //~~~ end of ACC payload

        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        printf("%ld ", elapsed);
    }

    printf("\nrror = %.10f\n", error);

    return 0;
}