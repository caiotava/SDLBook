#include<iostream>
#include<SDL.h>

SDL_Window *window = 0;
SDL_Renderer *renderer = 0;
bool running = false;

bool init(const char* title, int xPos, int yPos, int height, int width, int flags) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "error to initialize sdl2 system: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
        title,
        xPos,
        yPos,
        height,
        width,
        flags
    );

    if (!window) {
        std::cerr << "error to create a window: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        std::cerr << "error to create a window renderer: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

int main(int argc, char **argv) {
    running = init(
        "Chapter1: Setting up SDL.",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    if (!running) {
        return 1;
    }


    while (running) {
        render();
        SDL_Delay(20);
    }

    SDL_Quit();

    return 0;
}
