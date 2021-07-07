//
// Created by caiotava on 4/21/21.
//

#include "Game.h"
#include "MenuButton.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "StateParser.h"

const std::string PauseState::pauseID = "pause";

void PauseState::pauseToMain() {
    Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::resumePlay() {
    Game::Instance()->getStateMachine()->popState();
}

void PauseState::update() {
    for (auto& o : objects) {
        o->update();
    }
}

void PauseState::render() {
    for (auto& o : objects) {
        o->draw();
    }
}

bool PauseState::onEnter() {
    StateParser stateParser;

    stateParser.parseState("assets/test.xml", pauseID, &objects, &textureIDs);

    callbacks.push_back(0);
    callbacks.push_back(pauseToMain);
    callbacks.push_back(resumePlay);

    setCallbacks(callbacks);

    std::cout << "entering pause-state" << std::endl;
    return true;
}

bool PauseState::onExit() {
    for (auto& o : objects) {
        o->clean();
    }

    objects.clear();

    for (auto& t : textureIDs) {
        TextureManager::Instance()->clearFromTextureMap(t);
    }

    return true;
}

void PauseState::setCallbacks(const std::vector<Callback> &callbacks) {
    for (auto& o : objects) {
        if (!dynamic_cast<MenuButton*>(o)) {
            continue;
        }

        MenuButton* button = dynamic_cast<MenuButton*>(o);

        button->setCallback(callbacks[button->getCallbackID()]);
    }
}