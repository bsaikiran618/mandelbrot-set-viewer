LINKER_FLAGS = -lSDL2

window.o: Window.h Window.cpp
	g++ Window.cpp -c -o window.o;
main.o: main.cpp Window.h
	g++ main.cpp $(LINKER_FLAGS) -c -o main.o;
test: main.o
	g++ main.o window.o $(LINKER_FLAGS) -o test;
