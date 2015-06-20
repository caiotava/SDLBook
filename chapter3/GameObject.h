#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include<iostream>
#include<SDL2/SDL.h>

class GameObject
{
   public:
        void load(int pX, int pY, int pWidth, int pHeight, std::string pTextureId);
        void draw(SDL_Renderer *renderer);
        void update(); 
        void clean() { std::cout << "clean game object"; }

    protected:
        std::string textureId;

        int currentFrame;
        int currentRow;

        int x;
        int y;

        int width;
        int height;
};

#endif
