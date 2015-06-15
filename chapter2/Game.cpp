#include<iostream>
#include "Game.h"
#include"TextureManager.h"

bool Game::init(const char *title, int xPosition, int yPosition, int height, int width, bool fullScreen)
{
    int flags = SDL_WINDOW_SHOWN;

    if (fullScreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, xPosition, yPosition, height, width, flags);

    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == nullptr) {
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    TheTextureManager::getInstance()->load("assets/animate-alpha.png", "animate", renderer);

    running = true;
    return nullptr;
}

void Game::render()
{
    SDL_RenderClear(renderer);

    TheTextureManager::getInstance()->draw("animate", 0, 0, 128, 82, renderer);
    TheTextureManager::getInstance()->drawFrame("animate", 100, 100, 128, 82, 1, currentFrame, renderer);

    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;

    if (!SDL_PollEvent(&event)) {
        return;
    }

    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    currentFrame = int((SDL_GetTicks() / 100) % 6);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
