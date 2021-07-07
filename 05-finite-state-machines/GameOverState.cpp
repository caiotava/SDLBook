//
// Created by caiotava on 4/23/21.
//

#include "AnimatedGraphic.h"
#include "Game.h"
#include "GameOverState.h"
#include "MenuButton.h"
#include "MenuState.h"
#include "PlayState.h"
#include "TextureManager.h"

const std::string GameOverState::gameOverID = "GAMEOVER";

void GameOverState::update() {
    for (auto& o : objects) {
        o->update();
    }
}

void GameOverState::render() {
    for (auto& o : objects ) {
        o->draw();
    }
}

bool GameOverState::onEnter() {
    auto textMng = TextureManager::Instance();

    if (!textMng->load("assets/gameover.png", "gameovertext", Game::Instance()->getRenderer())) {
        return false;
    }

    if (!textMng->load("assets/main.png", "mainbutton", Game::Instance()->getRenderer())) {
        return false;
    }

    if (!textMng->load("assets/restart.png", "restartbutton", Game::Instance()->getRenderer())) {
        return false;
    }

    GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "gameovertext", 2), 2);
    GameObject* mainButton = new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton"), gameOverToMain);
    GameObject* restartButton = new MenuButton(new LoaderParams(200, 300, 200, 80, "restartbutton"), restartPlay);

    objects.push_back(gameOverText);
    objects.push_back(mainButton);
    objects.push_back(restartButton);

    std::cout << "entering pause-state" << std::endl;
    return true;
}

void GameOverState::gameOverToMain() {
    Game::Instance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::restartPlay() {
    Game::Instance()->getStateMachine()->changeState(new PlayState);
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

    TextureManager::Instance()->clearFromTextureMap("gameovertext");
    TextureManager::Instance()->clearFromTextureMap("mainbutton");
    TextureManager::Instance()->clearFromTextureMap("restartbutton");

    std::cout << "exiting GameOverState" << std::endl;
    return true;
}
