#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

#include<iostream>
#include<SDL2/SDL.h>

class GameObject
{
   public:
        virtual void load(int pX, int pY, int pWidth, int pHeight, std::string pTextureId);
        virtual void draw(SDL_Renderer *renderer);
        virtual void update();
        virtual void clean() {};

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
