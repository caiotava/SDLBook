#ifndef __GAME__
#define __GAME__

#include<vector>
#include<SDL2/SDL.h>
#include"GameObject.h"

class Game
{
    public:
        Game() {}
        ~Game() {}

        bool init(const char *title, int xPosition, int yPosition, int height, int width, bool fullScreen);

        void render();
        void update();
        void handleEvents();
        void clean();

        bool isRunning() { return running; }

    private:
        bool running;
        SDL_Window *window;
        SDL_Renderer *renderer;

        int currentFrame;

        std::vector<GameObject*> gameObjects;
};

#endif
