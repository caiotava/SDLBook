//
// Created by caiotava on 4/21/21.
//

#include "Enemy.h"
#include "Game.h"
#include "GameOverState.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "PlayState.h"
#include "Player.h"
#include "TextureManager.h"
#include<iostream>

const std::string PlayState::playID = "PLAY";

void PlayState::update() {
    if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }

    for (auto& o : objects) {
        o->update();
    }

    if (checkCollision(dynamic_cast<SDLGameObject*>(objects[0]), dynamic_cast<SDLGameObject*>(objects[1]))) {
        Game::Instance()->getStateMachine()->pushState(new GameOverState());
    }
}

void PlayState::render() {
    for (auto& o : objects) {
        o->draw();
    }
}

bool PlayState::onEnter() {
    if (!TextureManager::Instance()->load("assets/helicopter.png", "helicopter", Game::Instance()->getRenderer())) {
        return false;
    }

    if (!TextureManager::Instance()->load("assets/helicopter2.png", "helicopter2", Game::Instance()->getRenderer())) {
        return false;
    }

    GameObject* player = new Player(new LoaderParams(500, 100, 128, 55, "helicopter"));
    GameObject* enemy = new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2"));

    objects.push_back(player);
    objects.push_back(enemy);

    std::cout << "entering play state" << std::endl;
    return true;
}

bool PlayState::onExit() {
    for (auto& o : objects) {
        o->clean();
    }

    objects.clear();

    TextureManager::Instance()->clearFromTextureMap("helicopter");

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