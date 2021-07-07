//
// Created by caiotava on 4/17/21.
//

#include "Game.h"
#include "ShooterObject.h"
#include "TextureManager.h"

SDLGameObject::SDLGameObject() : GameObject() {
}

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

void SDLGameObject::load(std::unique_ptr<LoaderParams> const &params) {
    position = Vector2D(params->getX(), params->getY());
    velocity = Vector2D(0, 0);
    acceleration = Vector2D(0, 0);
    width = params->getWidth();
    height = params->getHeight();
    textureID = params->getTextureID();
    numFrames = params->getNumberFrames();

    currentFrame = 1;
    currentRow = 1;
}

void SDLGameObject::doDyingAnimation() {
    scroll(Game::Instance()->getScrollSpeed());

    currentFrame = int(SDL_GetTicks() / (1000 / 3) % numFrames);

    if (dyingCounter == dyingTime) {
        dead = true;
    }

    dyingCounter++;
}