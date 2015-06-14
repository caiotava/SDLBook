#include"TextureManager.h"

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer *renderer)
{
    SDL_Surface *surface = IMG_Load(fileName.c_str());

    if (surface == nullptr) {
        return false;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    if (texture == 0) {
        return false;
    }

    textureMap[id] = texture;
    return true;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;

    sourceRectangle.x = 0;
    sourceRectangle.y = 0;
    sourceRectangle.w = destinationRectangle.w = width;
    sourceRectangle.h = destinationRectangle.h = height;
    destinationRectangle.x = x;
    destinationRectangle.y = y;

    SDL_RenderCopyEx(renderer, textureMap[id], &sourceRectangle, &destinationRectangle, 0, 0, flip);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect sourceRectangle;
    SDL_Rect destinationRectangle;

    sourceRectangle.x = width * currentFrame;
    sourceRectangle.y = height * (currentRow - 1);
    sourceRectangle.w = destinationRectangle.w = width;
    sourceRectangle.h = destinationRectangle.h = height;
    destinationRectangle.x = x;
    destinationRectangle.y = y;

    SDL_RenderCopyEx(renderer, textureMap[id], &sourceRectangle, &destinationRectangle, 0, 0, flip);
}
