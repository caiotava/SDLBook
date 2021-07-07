//
// Created by caiotava on 4/14/21.
//

#include "TextureManager.h"
#include <SDL_image.h>

TextureManager *TextureManager::instance = 0;

TextureManager *TextureManager::Instance() {
    if (instance == 0) {
        instance = new TextureManager();
    }

    return instance;
}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *renderer) {
    SDL_Surface *surface = IMG_Load(fileName.c_str());

    if (!surface) {
        return false;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        return false;
    }

    textures[id] = texture;

    return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer,
                          SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(renderer, textures[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
                               SDL_Renderer *renderer, SDL_RendererFlip flip) {
    SDL_Rect srcRect;
    SDL_Rect destRect;

    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;

    destRect.x = x;
    destRect.y = y;

    SDL_RenderCopyEx(renderer, textures[id], &srcRect, &destRect, 0, 0, flip);
}
