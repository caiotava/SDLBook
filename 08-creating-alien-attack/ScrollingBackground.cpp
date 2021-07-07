//
// Created by caiotava on 4/27/21.
//

#include "ScrollingBackground.h"

#include "Game.h"

ScrollingBackground::ScrollingBackground() : SDLGameObject() {
    count = 0;
    maxCount = 10;
}

void ScrollingBackground::draw() {
    SDL_RenderCopyEx(
            Game::Instance()->getRenderer(),
            TextureManager::Instance()->getTextureMap()[textureID],
            &srcRect1,
            &destRect1,
            0,
            0,
            SDL_FLIP_NONE
    );

    SDL_RenderCopyEx(
            Game::Instance()->getRenderer(),
            TextureManager::Instance()->getTextureMap()[textureID],
            &srcRect2,
            &destRect2,
            0,
            0,
            SDL_FLIP_NONE
    );
}

void ScrollingBackground::update() {
    if (count != maxCount) {
        count++;
        return;
    }

    srcRect1.x += scrollSpeed;
    srcRect1.w -= scrollSpeed;
    destRect2.w -= scrollSpeed;

    srcRect2.w += scrollSpeed;
    destRect2.w += scrollSpeed;
    destRect2.x -= scrollSpeed;

    if (destRect2.w >= width) {
        initRects();
    }

    count = 0;
}

void ScrollingBackground::load(const std::unique_ptr<LoaderParams> &params) {
    SDLGameObject::load(std::move(params));

    scrollSpeed = 1;

    initRects();
}

void ScrollingBackground::initRects() {
    srcRect1.x = srcRect1.y = 0;
    destRect1.x = position.getX();
    destRect1.y = position.getY();

    srcRect1.w = destRect1.w = srcRect2Width = destRect1Width = width;
    srcRect1.h = destRect1.h = height;

    srcRect2.x = srcRect2.y = 0;
    destRect2.x = position.getX() + width;
    destRect2.y = position.getY();

    srcRect2.w = destRect2.w = srcRect2Width = destRect2Width = 0;
    srcRect2.h = destRect2.h = height;
}