//
// Created by caiotava on 4/15/21.
//

#ifndef SDLBOOK_CMAKE_GAME_H
#define SDLBOOK_CMAKE_GAME_H

#include "GameObject.h"
#include "GameStateMachine.h"
#include "TextureManager.h"
#include <SDL.h>
#include<vector>

class Game {
public:
    static Game *Instance();

    bool init(const char *title, int xPos, int yPos, int height, int width, bool fullscreen);

    void render();

    void update();

    void handleEvents();

    void clean();

    void setCurrentLevel(int currentLevel);

    void quit() { running = false; }

    bool isRunning() const {
        return running;
    }

    SDL_Renderer *getRenderer() const { return renderer; };

    GameStateMachine *getStateMachine() { return gameStateMachine; }

    int getGameWidth() const { return width; }

    int getGameHeight() const { return height; }

private:
    Game() {}

    bool running;
    int width;
    int height;
    int currentLevel;
    bool levelComplete;

    SDL_Window *window;
    SDL_Renderer *renderer;

    GameStateMachine *gameStateMachine;

    static Game *instance;
};

#endif //SDLBOOK_CMAKE_GAME_H
