#include"Game.h"
#include"SDLGameObject.h"
#include"TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams *pParams):
    GameObject(pParams),
    position(pParams->getX(),
    pParams->getY()),
    velocity(0, 0),
    acceleration(0, 0)
{
    width = pParams->getWidth();
    height = pParams->getHeight();
    textureId = pParams->getTextureId();

    currentRow = 1;
    currentFrame = 1;
}

void SDLGameObject::draw()
{
    SDL_RendererFlip rendererFlip = SDL_FLIP_NONE;

    if (velocity.getX() > 0) {
        rendererFlip = SDL_FLIP_HORIZONTAL;
    }

    TextureManager::getInstance()->drawFrame(
        textureId,
        position.getX(),
        position.getY(),
        width,
        height,
        currentRow,
        currentFrame,
        TheGame::getInstance()->getRenderer(),
        rendererFlip
    );
}

void SDLGameObject::update()
{
    velocity += acceleration;
    position += velocity;
}
