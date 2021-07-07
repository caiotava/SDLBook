//
// Created by caiotava on 4/17/21.
//

#include "Game.h"
#include "SDLGameObject.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject(const LoaderParams *params) :
        GameObject(params),
        position(params->getX(), params->getY()),
        velocity(0, 0),
        acceleration(0, 0) {
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getTextureID();

    currentFrame = 1;
    currentRow = 1;
}

void SDLGameObject::draw() {
    TextureManager::Instance()->drawFrame(
            textureID,
            position.getX(),
            position.getY(),
            width,
            height,
            currentRow,
            currentFrame,
            Game::Instance()->getRenderer()
    );
}

void SDLGameObject::update() {
    velocity += acceleration;
    position += velocity;
}