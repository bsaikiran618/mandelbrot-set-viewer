#include <iostream>
#include <stdlib.h>
#include <string>
#include <SDL2/SDL.h>

void err(std::string message)
{
	std::cerr << message << std::endl;
	exit(0);
}

int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0) err("Could not initialize SDL video!");

	return 0;
}
