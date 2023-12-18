ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

run: info.exe
	./bin/info$(ext)

info.exe: info.cpp
	gcc -x c++ -std=c++17 -fopenacc -o ./bin/info$(ext) info.cpp
