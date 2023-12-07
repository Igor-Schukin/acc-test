#include <cmath>
#include <cstdlib>
#include <ctime>
#include "definitions.h"
#include "function.h"

float riemannTest(const size_t intervals)
{
    TYPE sum = func(xmin), dx = (xmax - xmin) / intervals;
    for(int i = 1; i < intervals; i++)
    {
        sum += 2 * func(xmin + dx * i);
    }
    sum = (sum + func(xmax)) * dx / 2;
	
    return fabs(sum - integral<TYPE>(xmin, xmax));
}
