#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

#define MAX 100
#define MIN -100
#define TYPE double

float gaussTest(const size_t n)
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
	
    //~~~ transform matrix to triangular form
	
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
    
    x[n-1] = a[n-1][n] / a[n-1][n-1];

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

    TYPE err = 0;
    for(int i = 0; i < n; i++) {
        TYPE sum = 0;
        for (int j = 0; j < n; j++) {
            sum += x[j] * c[i][j];
        }
        TYPE rerr = fabs(c[i][n] - sum);
        if ( rerr > err) err = rerr;
    }
	
    return err;
}
