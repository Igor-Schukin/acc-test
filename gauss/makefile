ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

.DEFAULT_GOAL := all
.PHONY: all
.PRECIOUS: bin/gauss_%$(ext)

all: 0 1 2 3 4 0M 1M

%: bin/gauss_%$(ext) bin
	$<

bin/gauss_%$(ext): gauss.cpp gauss_%.o definitions.h
	g++ -std=c++17 -fopenacc  -o $@ $^

gauss_%.o: gauss_%.cpp definitions.h
	g++ -std=c++17 -fopenacc -O -c $^

bin:
	mkdir $@
