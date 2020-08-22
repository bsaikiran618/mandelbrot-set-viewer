#include "Window.h"
#include "Cartesian2D.h"

#include <complex>
#include <string>
#include <iostream>
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
		
		Cartesian2DPlane plane(SCREEN_W, SCREEN_H, 1.0);
		Cartesian2DPoint point1(0,0,&plane), point2(0,50,&plane);
		Cartesian2DPoint point3(-50,0,&plane), point4(50,0,&plane), point5(0,-50,&plane);
		SDL_SetRenderDrawColor(screenRenderer, 0,0,0,255);
		SDL_RenderClear(screenRenderer);
		SDL_SetRenderDrawColor(screenRenderer, 255,255,255,SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(screenRenderer, point1.getX(), point1.getY(), point2.getX(), point2.getY());
		SDL_RenderDrawLine(screenRenderer, point1.getX(), point1.getY(), point3.getX(), point3.getY());
		SDL_RenderDrawLine(screenRenderer, point1.getX(), point1.getY(), point4.getX(), point4.getY());
		SDL_RenderDrawLine(screenRenderer, point1.getX(), point1.getY(), point5.getX(), point5.getY());
		SDL_RenderPresent(screenRenderer);

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
