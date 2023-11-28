.PHONY: all
.PRECIOUS: bin/gauss_%.exe

%: bin/gauss_%.exe
	$<

bin/gauss_%.exe: gauss.cpp gauss_%.o
	g++ -std=c++17 -fopenacc  -o $@ $^

gauss_%.o: gauss_%.cpp
	g++ -std=c++17 -fopenacc -O -c $^
