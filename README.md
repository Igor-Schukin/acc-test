# Testing openACC with the GCC compiler

## Set of test tasks

1. ***vector_sum*** - reduction of the integer vector elements by sum
1. ***vector_add*** - addition of two integer vectors
1. ***riemann*** - the Riemann sum using rectangular, trapezoidal and Monte Carlo methods
1. ***gauss*** - solving a system of linear equations using the Gauss method

### Installing in Windows

1.  Before you can compile the examples, you will need a g++ compiler with openACC support.
    to check the current g++ version on you computer, type in command line:
    ```
    g++ --version
    ```
    If you have not g++ installed on you system, you can download and install [MinGW compiler collection] (https://sourceforge.net/projects/gcc-win64/)
    
1. Before you can compile the examples, you will need a g++ compiler and the make utility.