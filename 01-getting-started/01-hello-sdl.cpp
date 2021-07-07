#include<iostream>
#include<SDL.h>

SDL_Window *window = 0;
SDL_Renderer *renderer = 0;

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "error to initialize sdl2 system: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow(
        "Chapter1: Setting up SDL.",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "error to create a window: " << SDL_GetError() << std::endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        std::cerr << "error to create a window renderer: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(500);

    SDL_Quit();

    return 0;
}
