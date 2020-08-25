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
		
		Cartesian2DPlane plane(SCREEN_W, SCREEN_H, 1);
		//Cartesian2DPoint p1 (-10,0,&plane) , p2(10,0,&plane);
		//Cartesian2DPoint p3 (0,10,&plane) , p4(0,-10,&plane);
		Cartesian2DPoint p1(uint32_t(310),320, &plane);
		Cartesian2DPoint p2(uint32_t(330),320, &plane);
		Cartesian2DPoint p3(uint32_t(320),310, &plane);
		Cartesian2DPoint p4(uint32_t(320),330, &plane);

		std::cout << "P1 : " << p1.getX() << ',' << p1.getY() << std::endl;
		while(!appQuit)
		{
			SDL_SetRenderDrawColor(screenRenderer, 0,0,0,255);
			SDL_RenderClear(screenRenderer);
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
						case SDLK_UP: 		plane.translateUp();	break;
						case SDLK_DOWN: 	plane.translateDown();	break;
						case SDLK_LEFT: 	plane.translateLeft();	break;
						case SDLK_RIGHT: 	plane.translateRight();	break;
						case SDLK_KP_PLUS: 	plane.zoomIn();			break;
						case SDLK_KP_MINUS:	plane.zoomOut();		break;
					}
				}
			}
			SDL_SetRenderDrawColor(screenRenderer, 255,255,255,SDL_ALPHA_OPAQUE);
			SDL_RenderDrawLine(screenRenderer, p1.getX(), p1.getY(), p2.getX(), p2.getY());
			SDL_RenderDrawLine(screenRenderer, p3.getX(), p3.getY(), p4.getX(), p4.getY());
			SDL_RenderPresent(screenRenderer);
		}
		//event loop ends.
}
