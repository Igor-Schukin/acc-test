.PHONY: all
.PRECIOUS: bin/vector_add_%.exe

%: bin/vector_add_%.exe
	$< 0

bin/vector_add_%.exe: vector_add.cpp vector_add_%.o
	g++ -std=c++17 -fopenacc  -o $@ $^

vector_add_%.o: vector_add_%.cpp
	g++ -std=c++17 -fopenacc -O -c $^
