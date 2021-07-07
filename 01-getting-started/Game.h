//
// Created by caiotava on 4/10/21.
//

#ifndef SDLBOOK_CMAKE_GAME_H
#define SDLBOOK_CMAKE_GAME_H

#include<iostream>
#include "SDL.h"

class Game {
public:
    Game() {}
    ~Game() {}

    bool init(const char* title, int xPos, int yPos, int height, int width, bool fullscreen);

    void render();
    void update() {}
    void handleEvents();
    void clean ();

    bool isRunning() const {
        return running;
    }

private:
    bool running;

    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif //SDLBOOK_CMAKE_GAME_H
