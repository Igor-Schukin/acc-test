#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "definitions.h"
#include "function.h"

#pragma acc routine
TYPE inline random(TYPE min, TYPE max) {
    return min + (TYPE)rand() / RAND_MAX * (max - min);
}

float riemannTest(const size_t points)
{
    signed long long int count = 0;

    #pragma acc parallel loop reduction(+:count)
    for(int i = 0; i < points; i++)
    {
        TYPE x = random(xmin, xmax);
        TYPE y = random(ymin, ymax);
        TYPE f =  func(x);
        if (f > 0 && y < f && y > 0) count++;
        if (f < 0 && y > f && y < 0) count--;
    }
	

    TYPE sum = (TYPE)count / (TYPE)points * (xmax - xmin) * (ymax - ymin);

    return fabs(sum - integral<TYPE>(xmin, xmax));
}
