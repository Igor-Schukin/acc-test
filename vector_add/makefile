ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

.DEFAULT_GOAL := all
.PHONY: all
.PRECIOUS: bin/vector_add_%$(ext)

all: 0S 1S 2S 3S 4S 0D 1D 2D 3D 4D VA

%: bin/vector_add_%$(ext) bin
	$< 1000000

bin/vector_add_%$(ext): vector_add.cpp vector_add_%.o definitions.h
	g++ -std=c++17 -fopenacc  -o $@ $^

vector_add_%.o: vector_add_%.cpp definitions.h
	g++ -std=c++17 -fopenacc -O -c $^

bin:
	mkdir $@