//
// Created by caiotava on 4/10/21.
//

#include<iostream>
#include<SDL.h>
#include "Game.h"

int main(int argc, char **argv) {
    auto *game = new Game();

    game->init(
            "Chapter1: Setting up SDL.",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            640,
            480,
            true
    );

    while (game->isRunning()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();

    return 0;
}
