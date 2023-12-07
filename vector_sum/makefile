ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

.PHONY: all
.PRECIOUS: bin/vector_sum_%$(ext)

%: bin/vector_sum_%$(ext)
	$< 1000000

bin/vector_sum_%$(ext): vector_sum.cpp vector_sum_%.o definitions.h
	g++ -std=c++17 -fopenacc  -o $@ $^

vector_sum_%.o: vector_sum_%.cpp definitions.h
	g++ -std=c++17 -fopenacc -O -c $^
