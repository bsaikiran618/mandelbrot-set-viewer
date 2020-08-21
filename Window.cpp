#include "Window.h"
#include <string>
#include <SDL2/SDL.h>

Window::Window(std::string windowTitle, uint32_t flags)
{	
		if(SDL_Init(SDL_INIT_VIDEO) < 0) throw "Couldn't initialize SDL Video!";

		if((window = SDL_CreateWindow(windowTitle.c_str(), WINDOW_X, WINDOW_Y, SCREEN_W, SCREEN_H, flags)) == NULL)
			throw "Couldn't create SDL window!";

		windowSurface = SDL_GetWindowSurface(window);

		if((screenRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
			throw "Couldn't create SDL Renderer!";
}
void Window::startEventLoop()
{
		SDL_Event e;
		bool appQuit = false;
		while(!appQuit)
		{
			while(SDL_PollEvent(&e))
			{
				if(e.type == SDL_QUIT)
				{
					appQuit = true;
					break;
				}
				else if(e.type == SDL_KEYDOWN)
				{
					switch(e.key.keysym.sym)
					{
						case SDLK_UP: break;
						case SDLK_DOWN: break;
						case SDLK_LEFT: break;
						case SDLK_RIGHT: break;
					}
				}
			}
		}
		//event loop ends.
}
