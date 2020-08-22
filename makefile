LINKER_FLAGS = -lSDL2

test: main.o window.o cartesian2D.o
	g++ main.o window.o cartesian2D.o $(LINKER_FLAGS) -o test;
window.o: Window.h Window.cpp Cartesian2D.h
	g++ Window.cpp -c -o window.o;
cartesian2D.o: Cartesian2D.cpp Cartesian2D.h
	g++ Cartesian2D.cpp -c -o cartesian2D.o 
main.o: main.cpp Window.h
	g++ main.cpp $(LINKER_FLAGS) -c -o main.o;
