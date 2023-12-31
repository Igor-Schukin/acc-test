#include <cmath>
#include <cstdlib>
#include <ctime>
#include "definitions.h"
#include "function.h"

float riemannTest(const size_t intervals)
{
    TYPE sum = 0, dx = (xmax - xmin) / intervals;
    for(int i = 0; i < intervals; i++)
    {
        sum += func(xmin + dx * i);
    }
    sum *= dx;

    return fabs(sum - integral<TYPE>(xmin, xmax));
}
