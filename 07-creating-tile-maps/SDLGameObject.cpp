//
// Created by caiotava on 4/17/21.
//

#include "Game.h"
#include "SDLGameObject.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject() : GameObject(),
    position(0, 0),
    velocity(0, 0),
    acceleration(0, 0) {}

void SDLGameObject::draw() {
    auto flip = SDL_FLIP_NONE;

    if (velocity.getX() > 0) {
        flip = SDL_FLIP_HORIZONTAL;
    }

    TextureManager::Instance()->drawFrame(
            textureID,
            position.getX(),
            position.getY(),
            width,
            height,
            currentRow,
            currentFrame,
            Game::Instance()->getRenderer(),
            flip
    );
}

void SDLGameObject::update() {
    velocity += acceleration;
    position += velocity;
}

void SDLGameObject::load(const LoaderParams *params) {
    position = Vector2D(params->getX(), params->getY());
    velocity = Vector2D(0, 0);
    acceleration = Vector2D(0, 0);
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getTextureID();
    numberFrames = params->getNumberFrames();

    currentFrame = 1;
    currentRow = 1;
}

Vector2D &SDLGameObject::getPosition() {
    return position;
}

int SDLGameObject::getHeight() {
    return height;
}

int SDLGameObject::getWidth() {
    return width;
}