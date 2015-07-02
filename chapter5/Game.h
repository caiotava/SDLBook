#ifndef __GAME__
#define __GAME__

#include<vector>
#include<SDL2/SDL.h>
#include"GameObject.h"
#include"GameStateMachine.h"

class Game
{
    public:
        static Game *getInstance()
        {
            if (!instance) {
                instance = new Game();
            }

            return instance;
        }

        bool init(const char *title, int xPosition, int yPosition, int height, int width, bool fullScreen);

        void render();
        void update();
        void handleEvents();
        void clean();

        bool isRunning() { return running; }

        SDL_Renderer *getRenderer() const { return renderer; }

    private:
        static Game *instance;

        bool running;
        SDL_Window *window;
        SDL_Renderer *renderer;
        GameStateMachine *gameStateMachine;

        int currentFrame;

        std::vector<GameObject*> gameObjects;

        Game() {}
        ~Game() {}
};

typedef Game TheGame;

#endif
