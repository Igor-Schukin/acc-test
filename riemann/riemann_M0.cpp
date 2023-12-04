#include <cmath>
#include <cstdlib>
#include <ctime>

#include "function.h"

#define TYPE double

float riemannTest(const size_t intervals)
{
    TYPE* __restrict__ x = new TYPE[intervals];
    TYPE* __restrict__ y = new TYPE[intervals];

    //~~~ array of function values in nodes

    for(int i = 0; i < intervals; i++)
    {
        x[i] = xmin + (TYPE)rand() / RAND_MAX * (xmax - xmin);
        y[i] = ymin + (TYPE)rand() / RAND_MAX * (ymax - ymin);
    }
	
	//~~~ Reimann sum

    TYPE sum = 0;
    size_t count=0;
    for  (size_t i = 0; i < intervals; i++)
    {
        if (y[i] < func(x[i])) count++;
    }

    sum = (TYPE)count / (TYPE)intervals * (xmax - xmin) * ymax;

    delete[] x;
    delete[] y;
	
    return fabs(sum - integral<TYPE>(xmin, xmax));
}
