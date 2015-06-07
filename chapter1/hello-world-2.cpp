#include<iostream>
#include<SDL2/SDL.h>
#include"Game.h"

Game *game = 0;

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

int main(int argc, char **args)
{
	game = new Game();

    const char windowTitle[] = "Chapter 1: Setting up SDL";
	game->init(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_FULLSCREEN);

	while (game->isRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

    return 0;
}
