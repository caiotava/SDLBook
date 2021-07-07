//
// Created by caiotava on 4/15/21.
//

#ifndef SDLBOOK_CMAKE_GAME_H
#define SDLBOOK_CMAKE_GAME_H

#include<vector>
#include <SDL.h>
#include "TextureManager.h"
#include "GameObject.h"

class Game {
public:
    static Game *Instance();

    bool init(const char *title, int xPos, int yPos, int height, int width, bool fullscreen);

    void render();

    void update();

    void handleEvents();

    void clean();

    bool isRunning() const {
        return running;
    }

    SDL_Renderer *getRenderer() const { return renderer; };

private:
    Game() {}

    bool running;

    SDL_Window *window;
    SDL_Renderer *renderer;

    std::vector<GameObject*> objects;

    static Game *instance;
};

#endif //SDLBOOK_CMAKE_GAME_H
