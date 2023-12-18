ifeq ($(OS),Windows_NT)
	ext=.exe
else
	ext=
endif

run: info.exe
	./info$(ext)

info.exe: info.cpp
	gcc -x c++ -std=c++17 -fopenacc -o info$(ext) info.cpp
