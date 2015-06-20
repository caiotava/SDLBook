#include"GameObject.h"
#include"TextureManager.h"

void GameObject::load(int pX, int pY, int pWidth, int pHeight, std::string pTextureId)
{
    x = pX;
    y = pY;
    width = pWidth;
    height = pHeight;
    textureId = pTextureId;

    currentFrame = 1;
    currentRow = 1;
}

void GameObject::draw(SDL_Renderer *renderer)
{
    TextureManager::getInstance()->drawFrame(textureId, x, y, width, height, currentRow, currentFrame, renderer);
}

void GameObject::update()
{
    x++;
}
