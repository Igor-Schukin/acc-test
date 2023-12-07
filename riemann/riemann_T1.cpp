#include <cmath>
#include <cstdlib>
#include <ctime>
#include "definitions.h"
#include "function.h"

float riemannTest(const size_t intervals)
{
    TYPE sum = 0;

    #pragma acc kernels
    {
        TYPE dx = (xmax - xmin) / intervals;
        sum = func(xmin); 
        for(int i = 1; i < intervals; i++)
        {
            sum += 2 * func(xmin + dx * i);
        }
        sum = (sum + func(xmax)) * dx / 2;
    }
	
    return fabs(sum - integral<TYPE>(xmin, xmax));
}
