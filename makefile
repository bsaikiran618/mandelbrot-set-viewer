LINKER_FLAGS = -lSDL2

test: main.o window.o cartesian2D.o mandelbrot.o
	g++ main.o window.o cartesian2D.o mandelbrot.o $(LINKER_FLAGS) -o test;
mandelbrot.o: Mandelbrot.h Mandelbrot.cpp
	g++ Mandelbrot.cpp -c -o mandelbrot.o
window.o: Window.h Window.cpp Cartesian2D.h
	g++ Window.cpp -c -o window.o;
cartesian2D.o: Cartesian2D.cpp Cartesian2D.h
	g++ Cartesian2D.cpp -c -o cartesian2D.o 
main.o: main.cpp Window.h
	g++ main.cpp $(LINKER_FLAGS) -c -o main.o;
