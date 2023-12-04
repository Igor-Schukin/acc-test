#include <cmath>
#include <cstdlib>
#include <ctime>

#include "function.h"

#define TYPE double

float riemannTest(const size_t intervals)
{
    TYPE* __restrict__ f = new TYPE[intervals + 1];

    TYPE sum = 0;

    #pragma acc data
    {
        //~~~ array of function values in nodes

        TYPE dx = (xmax - xmin) / intervals;
        #pragma acc parallel loop
        for(int i = 0; i <= intervals; i++)
        {
            f[i] = func(xmin + dx * i);
        }
        
        //~~~ Reimann sum
        
        #pragma acc parallel loop reduction(+:sum)
        for(int i = 0; i < intervals; i++)
        {
            sum += f[i];
        }
        sum *= dx;
        
        delete[] f;
    }
	
    return fabs(sum - integral<TYPE>(xmin, xmax));
}
