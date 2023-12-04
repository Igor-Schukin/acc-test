.PHONY: all
.PRECIOUS: bin/riemann_%.exe

%: bin/riemann_%.exe
	$<

bin/riemann_%.exe: riemann.cpp riemann_%.o
	g++ -std=c++17 -fopenacc  -o $@ $^

riemann_%.o: riemann_%.cpp function.h
	g++ -std=c++17 -fopenacc -O -c $^
