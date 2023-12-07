#include <cmath>
#include <cstdlib>
#include <ctime>
#include "definitions.h"

#define ID(i, j) ((i)*(n+1)+(j))

float gaussTest(const size_t n)
{
    const size_t size = n*(n+1);  // array size

    TYPE* __restrict__ a = new TYPE[size];
    TYPE* __restrict__ c = new TYPE[size];
    TYPE* __restrict__ x = new TYPE[n];
	
    //~~~ initial matrix
	
    #pragma acc parallel loop
    for(int i = 0; i < size; i++)
    {
        a[i] = (TYPE)rand() / RAND_MAX * (MAX - MIN) + MIN;
    }
  	
    //~~~ matrix copy for final test
	
    #pragma acc parallel loop
    for(int i = 0; i < size; i++)
    {
        c[i] = a[i];
    }
	
    //~~~ transform matrix to a triangular form
	
    #pragma acc parallel loop
    for(int i = 0; i < n; i++)
    {
        #pragma acc loop
        for(int j = i + 1; j < n; j++)
        {
            TYPE ratio = a[ID(j,i)] / a[ID(i,i)];
            #pragma acc loop
            for(int k = i + 1; k <= n; k++)
            {
                a[ID(j, k)] = a[ID(j, k)] - ratio * a[ID(i,k)];
            }
        }
    }

    //~~~ calculate equation roots
    
    #pragma acc parallel loop
    for(int i = n-1; i >= 0; i--)
    {
        x[i] = a[ID(i,n)];
        #pragma acc loop
        for(int j = i+1; j < n; j++)
        {
            x[i] = x[i] - a[ID(i,j)] * x[j];
        }
        x[i] = x[i] / a[ID(i,i)];
    }
	
    //~~~ calculate error

    double err = 0;
    //#pragma acc parallel loop
    for(int i = 0; i < n; i++) {
        double sum = 0;
        //#pragma acc loop
        for (int j = 0; j < n; j++) {
            sum += x[j] * c[ID(i,j)];
        }
        err = std::max<double>(err, fabs(c[ID(i,n)] - sum));
    }

    delete[] a;
    delete[] c;
    delete[] x;

    return err;
}
