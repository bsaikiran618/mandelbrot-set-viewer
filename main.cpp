#include "Window.h"
#include <SDL2/SDL.h>

int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw "Couldn't start SDL!";
	}
	Window win("First Window",640,480);
	win.update();
	SDL_Delay(4000);
	return 0;
}
