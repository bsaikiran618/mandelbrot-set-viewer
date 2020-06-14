#include "Window.h"
#include <string>
#include <SDL2/SDL.h>

Window::Window(std::string title, unsigned int w, unsigned int h)
{
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w,h,SDL_WINDOW_SHOWN);
	if(!window)
	{
		throw new WindowError("Couldnt create a new window!");
	}
	windowSurface = SDL_GetWindowSurface(window);
	if(!windowSurface)
	{
		throw new WindowError("Couldnt obtain window surface!");
	}
}
Window::Window(std::string title,unsigned int w, unsigned int h, unsigned int win_x, unsigned int win_y)
{
	
	window = SDL_CreateWindow(title.c_str(), win_x, win_y, w, h, SDL_WINDOW_SHOWN);
	if(!window)
	{
		throw new WindowError("Couldnt create a new window!");
	}
	windowSurface = SDL_GetWindowSurface(window);
	if(!windowSurface)
	{
		throw new WindowError("Couldnt obtain window surface!");
	}
}
Window::Window(std::string title,unsigned int w, unsigned int h, unsigned int win_x, unsigned int win_y, uint32_t flgs)
{
	
	window = SDL_CreateWindow(title.c_str(), win_x, win_y, w, h, SDL_WINDOW_SHOWN|flgs);
	if(!window)
	{
		throw new WindowError("Couldnt create a new window!");
	}
	windowSurface = SDL_GetWindowSurface(window);
	if(!windowSurface)
	{
		throw new WindowError("Couldnt obtain window surface!");
	}
}
void Window::update()
{
	SDL_UpdateWindowSurface(window);
}
void Window::handleWindowEvents()
{
	bool quit = false;
	SDL_Event e;
	while(!quit)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT) quit = true;
		}
	}
}
Window::~Window()
{
	SDL_DestroyWindow(window);
}
