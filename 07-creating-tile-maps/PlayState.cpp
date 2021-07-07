//
// Created by caiotava on 4/21/21.
//

#include "Game.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include "LevelParser.h"
#include<iostream>

const std::string PlayState::playID = "play";

void PlayState::update() {
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }

    for (auto& o : objects) {
        o->update();
    }

    level->update();

   // if (checkCollision(dynamic_cast<SDLGameObject*>(objects[0]), dynamic_cast<SDLGameObject*>(objects[1]))) {
   //     Game::Instance()->getStateMachine()->pushState(new GameOverState());
   // }
}

void PlayState::render() {
    level->render();
}

bool PlayState::onEnter() {
    LevelParser levelParser;
    level = levelParser.parseLevel("assets/map.tmx");

    std::cout << "entering play state" << std::endl;
    return true;
}

bool PlayState::onExit() {
    for (auto& o : objects) {
        o->clean();
    }

    objects.clear();

    for (auto& t : textureIDs) {
        TextureManager::Instance()->clearFromTextureMap(t);
    }

    std::cout << "exiting play state" << std::endl;
    return true;
}

bool PlayState::checkCollision(SDLGameObject *p1, SDLGameObject *p2) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = p1->getPosition().getX();
    rightA = p1->getPosition().getX() + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = p1->getPosition().getY() + p1->getHeight();

    leftB = p2->getPosition().getX();
    rightB = p2->getPosition().getX() + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = p2->getPosition().getY() + p2->getHeight();

    if (bottomA <= topB) { return false; }
    if (topA >= bottomB) { return false; }
    if (rightA <= leftB) { return false; }
    if (leftA >= rightB) { return false; }

    return true;
}