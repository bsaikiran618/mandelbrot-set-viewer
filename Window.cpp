#include "Window.h"
#include "Cartesian2D.h"
#include "Mandelbrot.h"

#include <complex>
#include <string>
#include <iostream>
#include <SDL2/SDL.h>


void Window::drawAxes( Cartesian2DPlane *plane )
{
	Cartesian2DPoint leftExtreme	(double(0),	-1000,	plane);
	Cartesian2DPoint rightExtreme	(double(0),	1000,	plane);
	Cartesian2DPoint topExtreme		(double(1000), 0,		plane);
	Cartesian2DPoint bottomExtreme	(double(-1000),0, 	plane);

	SDL_SetRenderDrawColor(screenRenderer, 255,255,255,SDL_ALPHA_OPAQUE);
	//The X axis
	SDL_RenderDrawLine(screenRenderer, leftExtreme.getOnScreenX(), leftExtreme.getOnScreenY(),	
										rightExtreme.getOnScreenX(), rightExtreme.getOnScreenY());
	//The Y axis
	SDL_RenderDrawLine(screenRenderer, topExtreme.getOnScreenX(), topExtreme.getOnScreenY(),
										bottomExtreme.getOnScreenX(), bottomExtreme.getOnScreenY());
}

Window::Window(std::string windowTitle, uint64_t flags)
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
		while(!appQuit)
		{
			SDL_SetRenderDrawColor(screenRenderer, 0,0,0,SDL_ALPHA_OPAQUE);
			SDL_RenderClear(screenRenderer);

			for(uint64_t scr_x = 0; scr_x < plane.getWidth(); scr_x++)
			{
				for(uint64_t scr_y = 0; scr_y < plane.getHeight(); scr_y++)
				{
					//convert the screen coordinates to the cartesian plane coordinates
					Cartesian2DPoint p1(uint64_t(scr_x), uint64_t(scr_y), &plane);
					//convert cartesian plane coordinates to complex plane coordinates
					std::complex<double> p2(p1.getPlaneX(), p1.getPlaneY());
					if(inMandelbrotSet(p2, 15))
					{
						SDL_SetRenderDrawColor(screenRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
					}
					else
						SDL_SetRenderDrawColor(screenRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
					SDL_RenderDrawPoint(screenRenderer, p1.getOnScreenX(), p1.getOnScreenY());
				}
			}
			drawAxes(&plane);
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
			SDL_RenderPresent(screenRenderer);
		}
		//event loop ends.
}
