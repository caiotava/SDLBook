//
// Created by caiotava on 4/21/21.
//

#include "Game.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "PlayState.h"
#include "TextureManager.h"
#include<iostream>

const std::string MenuState::menuID = "MENU";

void MenuState::update() {
    for (auto &o : objects) {
        o->update();
    }
}

void MenuState::render() {
    for (auto &o : objects) {
        o->draw();
    }
}

void MenuState::menuToPlay() {
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::exitFromMenu() {
    Game::Instance()->quit();
}

bool MenuState::onEnter() {
    if (!TextureManager::Instance()->load("assets/button.png", "playbutton", Game::Instance()->getRenderer())) {
        return false;
    };

    if (!TextureManager::Instance()->load("assets/exit.png", "exitbutton", Game::Instance()->getRenderer())) {
        return false;
    }

    GameObject *playButton = new MenuButton(new LoaderParams(100, 100, 400, 100, "playbutton"), menuToPlay);
    GameObject *exitButton = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitbutton"), exitFromMenu);

    objects.push_back(playButton);
    objects.push_back(exitButton);

    std::cout << "entering menu-state" << std::endl;

    return true;
}

bool MenuState::onExit() {
    for (auto &o : objects) {
        o->clean();
    }

    objects.clear();

    TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");

    std::cout << "exiting menu-state" << std::endl;
    return true;
}