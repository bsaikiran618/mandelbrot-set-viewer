#ifndef WINDOW
#include <string>
#include <SDL2/SDL.h>
class Window
{
	public:
		SDL_Window *window;
		SDL_Surface *windowSurface;
		unsigned int windowHeight;
		unsigned int windowWidth;
		unsigned int windowX,windowY;
		uint32_t flags;
		std::string title;
		class WindowError
		{
			public:
				std::string message;
				WindowError(std::string m)
				:message(m)
				{
					
				}
		};
		Window(std::string title, unsigned int w, unsigned int h);
		Window(std::string title,unsigned int w, unsigned int h, unsigned int win_x, unsigned int win_y);
		Window(std::string title,unsigned int w, unsigned int h, unsigned int win_x, unsigned int win_y, uint32_t flgs);
		void update();
		~Window();
};
#endif
