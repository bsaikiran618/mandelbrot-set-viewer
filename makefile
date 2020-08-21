LINKER_FLAGS = -lSDL2

test: main.o
	g++ main.o $(LINKER_FLAGS) -o test;
main.o: main.cpp Screen.h
	g++ main.cpp $(LINKER_FLAGS) -c -o main.o
