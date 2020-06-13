main: Window.o Geometry.o main.cpp
	g++ Window.o Geometry.o main.cpp  -lSDL2 -o main
Window.o: Window.cpp Window.h
	g++ -c Window.cpp
Geometry.o: Geometry.cpp Window.h
	g++ -c Geometry.cpp
