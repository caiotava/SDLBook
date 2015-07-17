#include<SDL2/SDL.h>
#include"Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char **args)
{
    Uint32 frameStart, frameTime;
	Game *game = TheGame::getInstance();

    const char windowTitle[] = "Chapter 1: Setting up SDL";
	game->init(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);

	while (game->isRunning()) {
        frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME) {
            SDL_Delay((int) (DELAY_TIME - frameTime));
        }
    }

	game->clean();

    return 0;
}
