#include <cmath>
#include <cstdlib>
#include <ctime>

#define MAX 100
#define MIN -100
#define TYPE double
#define ID(i, j) ((i)*(n+1)+(j))

float gaussTest(const size_t n)
{
    const size_t size = n*(n+1);  // array size

    TYPE* __restrict__ a = new TYPE[size];
    TYPE* __restrict__ c = new TYPE[size];
    TYPE* __restrict__ x = new TYPE[n];

    //~~~ initial matrix
	
    for(int i = 0; i < size; i++)
    {
        a[i] = (TYPE)rand() / RAND_MAX * (MAX - MIN) + MIN;
    }
	
	//~~~ matrix copy for final test
	
    for(int i = 0; i < size; i++)
    {
        c[i] = a[i];
    }
	
    //~~~ transform matrix to a triangular form
	
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            TYPE ratio = a[ID(j,i)] / a[ID(i,i)];
            for(int k = i + 1; k <= n; k++)
            {
                a[ID(j, k)] = a[ID(j, k)] - ratio * a[ID(i,k)];
            }
        }
    }

    //~~~ calculate equation roots
    
    for(int i = n-1; i >= 0; i--)
    {
        x[i] = a[ID(i,n)];
        for(int j = i+1; j < n; j++)
        {
            x[i] = x[i] - a[ID(i,j)] * x[j];
        }
        x[i] = x[i] / a[ID(i,i)];
    }
	
    //~~~ calculate error

    double err = 0;
    for(int i = 0; i < n; i++) {
        double sum = 0;
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
