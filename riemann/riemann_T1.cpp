#include <cmath>
#include <cstdlib>
#include <ctime>

#include "function.h"

#define TYPE double

float riemannTest(const size_t intervals)
{
    TYPE* __restrict__ f = new TYPE[intervals + 1];

    //~~~ array of function values in nodes

    TYPE sum = 0;

    #pragma acc kernels
    {

        TYPE dx = (xmax - xmin) / intervals;
        for(int i = 0; i <= intervals; i++)
        {
            f[i] = func(xmin + dx * i);
        }
        
        //~~~ Reimann sum
        
        for(int i = 0; i < intervals; i++)
        {
            sum += f[i] + f[i+1];
        }
        sum = sum * dx / 2;
        
        delete[] f;
    }
	
    return fabs(sum - integral<TYPE>(xmin, xmax));
}
