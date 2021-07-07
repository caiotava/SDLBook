//
// Created by caiotava on 4/15/21.
//

#include<SDL.h>
#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char **argv) {
    Uint32 frameStart, frameTime;
    auto *game = Game::Instance();

    game->init(
            "Chapter1: Setting up SDL.",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            480,
            800,
            false
    );

    while (game->isRunning()) {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME) {
            SDL_Delay(DELAY_TIME - frameTime);
        };

        SDL_Delay(10);
    }

    game->clean();

    return 0;
}
