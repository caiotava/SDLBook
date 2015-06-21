#include"Game.h"

int main(int argc, char **args)
{
	Game *game = TheGame::getInstance();

    const char windowTitle[] = "Chapter 1: Setting up SDL";
	game->init(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false);

	while (game->isRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

    return 0;
}
