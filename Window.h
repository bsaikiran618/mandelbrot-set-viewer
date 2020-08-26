#ifndef SCREEN_HEADER_GUARD
#define SCREEN_HEADER_GUARD

#define WINDOW_X SDL_WINDOWPOS_CENTERED
#define WINDOW_Y SDL_WINDOWPOS_CENTERED
#define SCREEN_W 640
#define SCREEN_H 640

#include <SDL2/SDL.h>
#include <string>

class Window
{
	SDL_Window *window;
	SDL_Surface *windowSurface;
	SDL_Renderer *screenRenderer;
	
	public:
	Window(std::string windowTitle, uint64_t flags=SDL_WINDOW_SHOWN);
	void startEventLoop();
};

#endif
