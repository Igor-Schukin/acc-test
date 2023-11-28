#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <openacc.h>
#include <chrono>

#define type int

extern float gaussTest(const size_t n);

const size_t DEFAULT_MATRIX_SIZE = 1000;

int main(int argc, char *argv[])
{
    setlocale(LC_NUMERIC, "");
    srand(time(NULL));
    rand();

    //~~~ Determinate matrix size

    size_t size = DEFAULT_MATRIX_SIZE;
    if (argc > 1) size = std::stoull(argv[1]);

    printf("matrix size: %'d\n", size);

    auto start = std::chrono::system_clock::now();

    //~~~ ACC payload

    printf("Error = %.10f\n", gaussTest(size));

    //~~~ end of ACC payload

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    printf("elapsed time %'d ms\n", elapsed);

    return 0;
}