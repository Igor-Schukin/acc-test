ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

.PHONY: all
.PRECIOUS: bin/riemann_%$(ext)

%: bin/riemann_%$(ext)
	$<

bin/riemann_%$(ext): riemann.cpp riemann_%.o
	g++ -std=c++17 -fopenacc  -o $@ $^

riemann_%.o: riemann_%.cpp function.h
	g++ -std=c++17 -fopenacc -O -c $^
