//
// Created by caiotava on 4/14/21.
//

#ifndef SDLBOOK_CMAKE_TEXTUREMANAGER_H
#define SDLBOOK_CMAKE_TEXTUREMANAGER_H

#include <string>
#include <map>
#include <SDL.h>

class TextureManager {
public:
    static TextureManager *Instance();

    bool load(std::string fileName, std::string id, SDL_Renderer *renderer);

    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer,
              SDL_RendererFlip flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
                   SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
    std::map<std::string, SDL_Texture *> textures;
    static TextureManager *instance;

    TextureManager() {}
};


#endif //SDLBOOK_CMAKE_TEXTUREMANAGER_H
