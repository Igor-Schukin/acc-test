ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

run: bin bin/info$(ext)
	./bin/info$(ext)

bin/info$(ext): info.cpp
	g++ -std=c++17 -fopenacc -o ./bin/info$(ext) info.cpp

bin:
	mkdir $@
