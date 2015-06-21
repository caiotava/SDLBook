#include"Game.h"
#include"SDLGameObject.h"
#include"TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams *pParams): GameObject(pParams)
{
    x = pParams->getX();
    y = pParams->getY();
    width = pParams->getWidth();
    height = pParams->getHeight();
    textureId = pParams->getTextureId();

    currentRow = 1;
    currentFrame = 1;
}

void SDLGameObject::draw()
{
    TextureManager::getInstance()->drawFrame(textureId, x, y, width, height, currentRow, currentFrame, TheGame::getInstance()->getRenderer());
}
