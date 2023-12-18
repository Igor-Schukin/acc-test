ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

.DEFAULT_GOAL := all
.PHONY: all
.PRECIOUS: bin/riemann_%$(ext)

all: R0 R1 R2 T0 T1 T2 M0 M1 M2

%: bin/riemann_%$(ext) bin
	$<

bin/riemann_%$(ext): riemann.cpp riemann_%.o
	g++ -std=c++17 -fopenacc  -o $@ $^

riemann_%.o: riemann_%.cpp function.h
	g++ -std=c++17 -fopenacc -O -c $^

bin:
	mkdir $@
