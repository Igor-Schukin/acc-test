ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

.PHONY: all
.PRECIOUS: bin/vector_add_%$(ext)

%: bin/vector_add_%$(ext)
	$< 1000000

bin/vector_add_%$(ext): vector_add.cpp vector_add_%.o definitions.h
	g++ -std=c++17 -fopenacc  -o $@ $^

vector_add_%.o: vector_add_%.cpp definitions.h
	g++ -std=c++17 -fopenacc -O -c $^
