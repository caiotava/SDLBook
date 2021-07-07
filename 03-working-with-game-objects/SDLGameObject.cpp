//
// Created by caiotava on 4/17/21.
//

#include "Game.h"
#include "SDLGameObject.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams *params) : GameObject(params) {
    x = params->getX();
    y = params->getY();
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getTextureID();

    currentFrame = 1;
    currentRow = 1;
}

void SDLGameObject::draw() {
    TextureManager::Instance()->drawFrame(
            textureID,
            x,
            y,
            width,
            height,
            currentRow,
            currentFrame,
            Game::Instance()->getRenderer()
    );
}