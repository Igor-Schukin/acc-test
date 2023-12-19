# Testing openACC with the GCC compiler

## Set of test tasks

1. ***vector_sum*** - reduction of the integer vector elements by sum
1. ***vector_add*** - addition of two integer vectors
1. ***riemann*** - the Riemann sum using rectangular, trapezoidal and Monte Carlo methods
1. ***gauss*** - solving a system of linear equations using the Gauss method

## Useful links

1.  GCC Wiki: [GCC's implementation of the OpenACC specification](https://gcc.gnu.org/wiki/OpenACC)
1.  [Introduction to OpenACC Programming Model](https://ulhpc-tutorials.readthedocs.io/en/latest/gpu/openacc/basics/)
1.  [OpenACC resources](https://www.openacc.org/resources)
1.  [Popular github repositories](https://github.com/OpenACC)
1.  [NVIDIA HPC SDK](https://developer.nvidia.com/hpc-sdk)
1.  [PGI Compilers & Tools](https://www.pgroup.com/index.htm)
1.  [Downloads & Tools](https://www.openacc.org/tools)

## Preparing a Windows system

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
    If you don't have make utitity on your system, you can download and install [GNU tools for Windows](https://sourceforge.net/projects/gnuwin32/)

1.  You can now clone the test source files. Navigate to the folder where you want to place the source files folder:
    ```
    cd the_root_forder_for_project_files
    ```
    and copy test sources from the repository:
    ```
    git clone git@github.com:Igor-Schukin/acc-test.git
    ```

1.  Final test. To make sure everything runs without errors, you can build and run the first test:
    ```
    cd acc-test\.info
    make
    ```
    You have to see something like this:
    ```
    mkdir bin
    g++ -std=c++17 -fopenacc -o ./bin/info.exe info.cpp
    ./bin/info.exe
    openACC version 201711
    current device type 2
    number of devices 1
    current device 0
        size of device memory in bytes 0
        free device memory in bytes 0
        device vendor GOMP
        device driver version 1.0
    ```

1.  If everything is ok, we can start testing openACC.

## Preparing a Linux system

1.  Before start, you will need a g++ compiler with openACC support. To check the current version of g++ on your computer, enter the following command at the command prompt:
    ```
    g++ --version
    ```
    The answer should be something like this:
    ```
    g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
    Copyright (C) 2021 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    ```
    Please note that you will need at least version 10 of g++!
    If you don't have appropriate g++ version on your system, you can install it using a package manager:
    ```
    sudo apt install gcc g++
    ```

1. You will also need the make utility to build the tests. To check the availability and version of make, enter the following command at the command prompt:
    ```
    make --version
    ```
    The response should be something like this:
    ```
    GNU Make 4.3
    Built for x86_64-pc-linux-gnu
    Copyright (C) 1988-2020 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.
    ```
    If you don't have make utility on your system, you can install it using a package manager:
    ```
    sudo apt install make
    ```

1.  You can now clone the test source files. Navigate to the folder where you want to place the source files folder:
    ```
    cd the_root_forder_for_project_files
    ```
    and copy test sources from the repository:
    ```
    git clone git@github.com:Igor-Schukin/acc-test.git
    ```

1.  Final test. To make sure everything runs without errors, you can build and run the first test:
    ```
    cd acc-test/.info
    make
    ```
    You have to see something like this:
    ```
    mkdir bin
    g++ -std=c++17 -fopenacc -o ./bin/info info.cpp
    ./bin/info
    openACC version 201711
    current device type 2
    number of devices 1
    current device 0
        size of device memory in bytes 0
        free device memory in bytes 0
        device vendor GOMP
        device driver version 1.0
    ```

1.  If everything is ok, we can start testing openACC.

## Versions of tests

### ***vector_sum*** - reduction of the integer vector elements by sum
    ***0S*** - basic version without openACC, one loop without explicit separation into chunks,
    ***0D*** - basic version without openACC, explicit separation into chunks using two nested loops,
    ***1S*** - using acc kernels, one loop without explicit separation into chunks,
    ***1D*** - using acc kernels, explicit separation into chunks using two nested loops,
    ***2S*** - using acc parallel loop, one loop without explicit separation into chunks,
    ***2D*** - using acc parallel loop, explicit separation into chunks using two nested loops,
    ***3S*** - using acc data, one loop without explicit separation into chunks,
    ***3D*** - using acc data, explicit separation into chunks using two nested loops,
    ***3S*** - using acc data, one loop without explicit separation into chunks,
    ***3D*** - using acc data, explicit separation into chunks using two nested loops,
    ***4S*** - using acc data create, one loop without explicit separation into chunks,
    ***4D*** - using acc data create, explicit separation into chunks using two nested loops,
    ***VA*** - using C++ template std::valarray, one loop without explicit separation into chunks,
### ***vector_add*** - addition of two integer vectors
### ***riemann*** - the Riemann sum using rectangular, trapezoidal and Monte Carlo methods
### ***gauss*** - solving a system of linear equations using the Gauss method