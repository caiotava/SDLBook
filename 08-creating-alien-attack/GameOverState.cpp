//
// Created by caiotava on 4/23/21.
//

#include "Game.h"
#include "GameOverState.h"
#include "MenuButton.h"
#include "MainMenuState.h"
#include "StateParser.h"
#include "PlayState.h"
#include "TextureManager.h"

const std::string GameOverState::gameOverID = "gameover";

void GameOverState::update() {
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->update();
    }
}

void GameOverState::render() {
    for (auto& o : objects ) {
        o->draw();
    }
}

bool GameOverState::onEnter() {
    StateParser stateParser;
    stateParser.parseState("assets/test.xml", gameOverID, &objects, &textureIDs);

    callbacks.push_back(0);
    callbacks.push_back(gameOverToMain);
    callbacks.push_back(restartPlay);

    setCallbacks(callbacks);

    std::cout << "entering pause-state" << std::endl;
    return true;
}

void GameOverState::gameOverToMain() {
    Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::restartPlay() {
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

bool GameOverState::onExit()
{
    if (!objects.empty())
    {
        for (auto& o : objects) {
            o->clean();
            delete o;
        }

        objects.clear();
    }

    std::cout << objects.size() << std::endl;

    for (auto& t : textureIDs) {
        TextureManager::Instance()->clearFromTextureMap(t);
    }

    std::cout << "exiting GameOverState" << std::endl;
    return true;
}
void GameOverState::setCallbacks(const std::vector<Callback> &callbacks) {
    for (auto& o : objects) {
        if (!dynamic_cast<MenuButton*>(o)) {
            continue;
        }

        MenuButton* button = dynamic_cast<MenuButton*>(o);

        button->setCallback(callbacks[button->getCallbackID()]);
    }
}
