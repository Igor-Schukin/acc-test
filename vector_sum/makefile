.PHONY: all
.PRECIOUS: bin/vector_sum_%.exe

%: bin/vector_sum_%.exe
	$< 0

bin/vector_sum_%.exe: vector_sum.cpp vector_sum_%.o
	g++ -std=c++17 -fopenacc  -o $@ $^

vector_sum_%.o: vector_sum_%.cpp
	g++ -std=c++17 -fopenacc -O -c $^
