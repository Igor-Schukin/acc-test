#include <cmath>
#include <cstdlib>
#include <ctime>
#include "definitions.h"
#include "function.h"

TYPE inline random(TYPE min, TYPE max) {
    return min + (TYPE)rand() / RAND_MAX * (max - min);
}

float riemannTest(const size_t points)
{
    signed long long int count = 0;

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
