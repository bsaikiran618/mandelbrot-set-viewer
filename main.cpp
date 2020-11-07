/*

======================== MANDELBROT SET VIEWER GOALS=======================
	1) Render the mandelbrot set
	2) Make it interactive:
		a) Use + for zooming in
		b) Use - for zooming out
		c) Use LEFT,RIGHT,UP,DOWN for translation
	3) Render it in multiple colors.
*/

#include <iostream>
#include <stdlib.h>
#include <string>

#include "Window.h"

void err(std::string message)
{
	std::cerr << message << std::endl;
	exit(0);
}

int main()
{
	try
	{
		Window appWindow("SK's Mandelbrot Set Viewer", SDL_WINDOW_SHOWN);
		appWindow.startEventLoop();
	}
	catch(std::string errMsg)
	{
		std::cerr << errMsg << std::endl;
		exit(-1);
	}
	catch(...)
	{
		std::cerr << "An unknown error occured!" << std::endl;
		exit(-1);
	}
	return 0;
}
