ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

.DEFAULT_GOAL := all
.PHONY: all
.PRECIOUS: bin/vector_sum_%$(ext)

all: 0S 1S 2S 3S 4S 0D 1D 2D 3D 4D VA

%: bin/vector_sum_%$(ext)
	$< 1000000

bin/vector_sum_%$(ext): vector_sum.cpp vector_sum_%.o definitions.h
	g++ -std=c++17 -fopenacc  -o $@ $^

vector_sum_%.o: vector_sum_%.cpp definitions.h
	g++ -std=c++17 -fopenacc -O -c $^
