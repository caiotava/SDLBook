//
// Created by caiotava on 4/10/21.
//

#include "Game.h"

bool Game::init(const char *title, int xPos, int yPos, int height, int width, bool fullscreen) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    std::cout << "SDL init success\n";

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

    if (window == 0) {
        std::cout << "windows creation unsuccessful" << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == 0) {
        std::cout << "renderer creation unsuccessful" << std::endl;
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    running = true;

    return true;
}

void Game::handleEvents() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }
}

void Game::render() {
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    std::cout << "cleaning game" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}