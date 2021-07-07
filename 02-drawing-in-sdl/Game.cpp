//
// Created by caiotava on 4/10/21.
//

#include "Game.h"
#include<SDL_image.h>

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

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    running = true;

    TextureManager::Instance()->load("assets/rider.bmp", "rider", renderer);
    TextureManager::Instance()->load("assets/animate-alpha.png", "animate", renderer);

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

    TextureManager::Instance()->draw("rider", 0, 0, 128, 82, renderer);
    TextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, currentFrame, renderer);

    SDL_RenderPresent(renderer);
}

void Game::update() {
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Game::clean() {
    std::cout << "cleaning game" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}