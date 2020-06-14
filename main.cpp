#include "Window.h"
#include <SDL2/SDL.h>

int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw "Couldn't start SDL!";
	}
	Window win("Mandelbrot Set Viewer",640,480);
	win.update();
	win.handleWindowEvents();
	return 0;
}
