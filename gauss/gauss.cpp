#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <openacc.h>
#include <chrono>
#include "definitions.h"

extern float gaussTest(const size_t n);

const size_t DEFAULT_MATRIX_SIZE = 100;
const size_t MAX_MATRIX_SIZE = 47000;

int main(int argc, char *argv[])
{
    setlocale(LC_NUMERIC, "");
    srand(time(NULL));
    rand();

    //~~~ Determinate matrix size

    size_t size = DEFAULT_MATRIX_SIZE;
    if (argc > 1) size = std::stoull(argv[1]);
    int count = 1;
    if (argc == 3) count = std::stoi(argv[2]);

    printf("matrix size: %'ld\n", size);

    printf("elapsed time, ms: ");
    float error = 0;

    for (int i = 0; i < count; i++) {

        auto start = std::chrono::system_clock::now();

        //~~~ ACC payload

        float res = gaussTest(size);
        if (res > error) error = res;

        //~~~ end of ACC payload

        auto end = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        printf("%ld ", elapsed);
    }

    printf("\nError = %.10f\n", error);

    return 0;
}