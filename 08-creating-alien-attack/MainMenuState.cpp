//
// Created by caiotava on 4/24/21.
//

#include "Game.h"
#include "MainMenuState.h"
#include "StateParser.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "TextureManager.h"
#include<iostream>

const std::string MainMenuState::menuID = "menu";

void MainMenuState::update() {
    for (auto &o : objects) {
        o->update();
    }
}

void MainMenuState::render() {
    for (auto &o : objects) {
        o->draw();
    }
}

void MainMenuState::menuToPlay() {
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::exitFromMenu() {
    Game::Instance()->quit();
}

bool MainMenuState::onEnter() {
    StateParser stateParser;

    stateParser.parseState("assets/test.xml", menuID, &objects, &textureIDs);

    callbacks.push_back(0);
    callbacks.push_back(menuToPlay);
    callbacks.push_back(exitFromMenu);

    setCallbacks(callbacks);

    std::cout << "entering menu-state" << std::endl;

    return true;
}

bool MainMenuState::onExit() {
    for (auto &o : objects) {
        o->clean();
    }

    objects.clear();

    for (auto& t : textureIDs) {
        TextureManager::Instance()->clearFromTextureMap(t);
    }

    std::cout << "exiting menu-state" << std::endl;
    return true;
}

void MainMenuState::setCallbacks(const std::vector<Callback> &callbacks) {
    for (auto& o : objects) {
        if (!dynamic_cast<MenuButton*>(o)) {
            continue;
        }

        MenuButton* button = dynamic_cast<MenuButton*>(o);

        button->setCallback(callbacks[button->getCallbackID()]);
    }
}