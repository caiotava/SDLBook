//
// Created by caiotava on 4/21/21.
//

#include "Game.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "PauseState.h"

const std::string PauseState::pauseID = "PAUSE";

void PauseState::pauseToMain() {
    Game::Instance()->getStateMachine()->changeState(new MenuState());
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
    if (!TextureManager::Instance()->load("assets/resume.png", "resumebutton", Game::Instance()->getRenderer())) {
        return false;
    }

    if (!TextureManager::Instance()->load("assets/main.png", "mainbutton", Game::Instance()->getRenderer())) {
        return false;
    }

    GameObject* resumeButton = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton"), pauseToMain);
    GameObject* mainButton = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton"), resumePlay);

    objects.push_back(resumeButton);
    objects.push_back(mainButton);
}

bool PauseState::onExit() {
    for (auto& o : objects) {
        o->clean();
    }

    objects.clear();

    TextureManager::Instance()->clearFromTextureMap("mainbutton");
    TextureManager::Instance()->clearFromTextureMap("resumebutton");
}