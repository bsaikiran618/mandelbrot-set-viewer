#ifndef SCREEN_HEADER_GUARD
#define SCREEN_HEADER_GUARD

#define WINDOW_X SDL_WINDOWPOS_CENTERED
#define WINDOW_Y SDL_WINDOWPOS_CENTERED
#define SCREEN_W 640
#define SCREEN_H 480

#include <SDL2/SDL.h>
#include <string>

class Window
{
	SDL_Window *window;
	SDL_Surface *windowSurface;
	SDL_Renderer *screenRenderer;
	
	public:

	Window(std::string windowTitle, uint32_t flags=SDL_WINDOW_SHOWN)
	{	
		if(SDL_Init(SDL_INIT_VIDEO) < 0) throw "Couldn't initialize SDL Video!";

		if((window = SDL_CreateWindow(windowTitle.c_str(), WINDOW_X, WINDOW_Y, SCREEN_W, SCREEN_H, flags)) == NULL)
			throw "Couldn't create SDL window!";

		windowSurface = SDL_GetWindowSurface(window);

		if((screenRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
			throw "Couldn't create SDL Renderer!";
	}
	void startEventLoop()
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
			}
		}
		//event loop ends.
	}
};

#endif
