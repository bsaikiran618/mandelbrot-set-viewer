#include "Window.h"
#include "Cartesian2D.h"
#include "Mandelbrot.h"

#include <complex>
#include <string>
#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>


void Window::drawAxes( Cartesian2DPlane *plane )
{
	Cartesian2DPoint leftExtreme	(double(0),	-2000,	plane);
	Cartesian2DPoint rightExtreme	(double(0),	2000,	plane);
	Cartesian2DPoint topExtreme		(double(2000), 0,		plane);
	Cartesian2DPoint bottomExtreme	(double(-2000),0, 	plane);

	SDL_SetRenderDrawColor(screenRenderer, 120,120,120,SDL_ALPHA_OPAQUE);
	//The X axis
	SDL_RenderDrawLine(screenRenderer, leftExtreme.getOnScreenX(), leftExtreme.getOnScreenY(),
										rightExtreme.getOnScreenX(), rightExtreme.getOnScreenY());
	//The Y axis
	SDL_RenderDrawLine(screenRenderer, topExtreme.getOnScreenX(), topExtreme.getOnScreenY(),
										bottomExtreme.getOnScreenX(), bottomExtreme.getOnScreenY());
}
void Window::drawScreen(Cartesian2DPlane *plane)
{
			SDL_SetRenderDrawColor(screenRenderer, 0,0,0,SDL_ALPHA_OPAQUE);
			SDL_RenderClear(screenRenderer);

			for(uint64_t scr_x = 0; scr_x < plane->getWidth(); scr_x++)
			{
				for(uint64_t scr_y = 0; scr_y < plane->getHeight(); scr_y++)
				{
					//convert the screen coordinates to the cartesian plane coordinates
					Cartesian2DPoint p1(uint64_t(scr_x), uint64_t(scr_y), plane);
					//convert cartesian plane coordinates to complex plane coordinates
					//std::complex<double> p2(p1.getPlaneX(), p1.getPlaneY());
					std::complex<double> p2(-p1.getPlaneY(), p1.getPlaneX());
					int c;
					if((c = inMandelbrotSet(p2, 50)) != -1)
					{
						/*
						int r = int(c * 0.01 * 255)%255;
						int g = int(c * 0.03 * 255)%255;
						int b = int(c * 0.05 * 255)%255;
						*/
						long int r,g,b;
						if(c != 0)
						{
							r = (c) % 256;
							g = (c*c) % 256;
							b = (c*c+c) % 256;
						}else r = g = b = 0;
						SDL_SetRenderDrawColor(screenRenderer, r, g, b, SDL_ALPHA_OPAQUE);
					}
					else
						SDL_SetRenderDrawColor(screenRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
					SDL_RenderDrawPoint(screenRenderer, p1.getOnScreenX(), p1.getOnScreenY());
				}
			}
			drawAxes(plane);
			SDL_RenderPresent(screenRenderer);
}

Window::Window(std::string windowTitle, uint64_t flags)
{	
		if(SDL_Init(SDL_INIT_VIDEO) < 0) throw "Couldn't initialize SDL Video!";

		if((window = SDL_CreateWindow(windowTitle.c_str(), WINDOW_X, WINDOW_Y, SCREEN_W, SCREEN_H, flags)) == NULL)
			throw "Couldn't create SDL window!";

		//windowSurface = SDL_GetWindowSurface(window);

		if((screenRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
			throw "Couldn't create SDL Renderer!";
}
void Window::startEventLoop()
{
		SDL_Event e;
		bool appQuit = false;
		bool changed = false;
		srand(42);
		
		Cartesian2DPlane plane(SCREEN_W, SCREEN_H, 150);
		drawScreen(&plane);
		while(!appQuit)
		{
			changed = false;
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
						case SDLK_UP: 		plane.translateUp();	changed = true;break;
						case SDLK_DOWN: 	plane.translateDown();	changed = true;break;
						case SDLK_LEFT: 	plane.translateLeft();	changed = true;break;
						case SDLK_RIGHT: 	plane.translateRight();	changed = true;break;
						case SDLK_KP_PLUS: 	plane.zoomIn();			changed = true;break;
						case SDLK_KP_MINUS:	plane.zoomOut();		changed = true;break;
					}
				}
			}
			if(changed) drawScreen(&plane);
		}
		//event loop ends.
}
