#ifndef __TEXTURE_MANAGER__
#define __TEXTURE_MANAGER__

#include<iostream>
#include<map>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class TextureManager
{
    public:
        bool load(std::string fileName, std::string id, SDL_Renderer *renderer);
        void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
        void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

        static TextureManager* getInstance()
        {
            if (!instance) {
                instance = new TextureManager();
            }

            return instance;
        }

    private:
        std::map<std::string, SDL_Texture*> textureMap;

        static TextureManager *instance;

        TextureManager() {};
};

typedef TextureManager TheTextureManager;

#endif
