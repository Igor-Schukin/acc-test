#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

#define MAX 100
#define MIN -100
#define TYPE double

float gaussTest(const size_t n)
{
    double err = 0;
    
    #pragma acc kernels
    {

        TYPE a[n][n+1], c[n][n+1], x[n];

        //~~~ initial matrix
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= n; j++)
                a[i][j] = (TYPE)rand() / RAND_MAX * (MAX - MIN) + MIN;
        
        //~~~ matrix copy for final test
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= n; j++)
                c[i][j] = a[i][j];
        
        //~~~ transform matrix to a triangular form
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                TYPE ratio = a[j][i] / a[i][i];
                for(int k = i + 1; k <= n; k++)
                {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }
            }
        }

        //~~~ calculate equation roots
        
        for(int i = n-1; i >= 0; i--)
        {
            x[i] = a[i][n];
            for(int j = i+1; j < n; j++)
            {
                x[i] = x[i] - a[i][j] * x[j];
            }
            x[i] = x[i] / a[i][i];
        }
        
        //~~~ calculate error

        for(int i = 0; i < n; i++) {
            double e = 0;
            for (int j = 0; j < n; j++) {
                e += x[j] * c[i][j];
            }
            e = fabs(c[i][n] - e);
            if ( e > err) err = e;
        }
    }

    return err;
}
