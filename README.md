# Testing openACC with the GCC compiler

## Set of test tasks

1. ***vector_sum*** - reduction of the integer vector elements by sum
1. ***vector_add*** - addition of two integer vectors
1. ***riemann*** - the Riemann sum using rectangular, trapezoidal and Monte Carlo methods
1. ***gauss*** - solving a system of linear equations using the Gauss method

### Installing in Windows

1.  Before start, you will need a g++ compiler with openACC support. To check the current version of g++ on your computer, enter the following command at the command prompt:
    ```
    g++ --version
    ```
    The answer should be something like this:
    ```
    g++.exe (GCC) 13.2.0
    Copyright (C) 2023 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    ```
    Please note that you will need at least version 10 of g++!
    If you don't have appropriate g++ version on your system, you can download and install [MinGW compiler collection](https://sourceforge.net/projects/gcc-win64/)

1. You will also need the make utility to build the tests. To check the availability and version of make, enter the following command at the command prompt:
    ```
    make --version
    ```
    The response should be something like this:
    ```
    GNU Make 3.81
    Copyright (C) 2006  Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.
    There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
    PARTICULAR PURPOSE.
    This program built for i386-pc-mingw32
    ```
    If you don't make utitity on your system, you can download and install [GNU tools for Windows](https://sourceforge.net/projects/gnuwin32/)