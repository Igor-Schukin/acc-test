ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

.PHONY: all
.PRECIOUS: bin/gauss_%$(ext)

%: bin/gauss_%$(ext)
	$<

bin/gauss_%$(ext): gauss.cpp gauss_%.o definitions.h
	g++ -std=c++17 -fopenacc  -o $@ $^

gauss_%.o: gauss_%.cpp definitions.h
	g++ -std=c++17 -fopenacc -O -c $^
