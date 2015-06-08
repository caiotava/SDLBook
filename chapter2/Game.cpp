#include<iostream>
#include "Game.h"

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

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	SDL_Surface *surface = SDL_LoadBMP("assets/rider.bmp");

	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_FreeSurface(surface);

	SDL_QueryTexture(texture, NULL, NULL, &sourceRectangle.w, &sourceRectangle.h);

	destinationRectangle.x = 0;
	destinationRectangle.y = 0;
	destinationRectangle.w = sourceRectangle.w;
	destinationRectangle.h = sourceRectangle.h;

    running = true;
    return nullptr;
}

void Game::render()
{
    SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, texture, &sourceRectangle, &destinationRectangle);

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

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
