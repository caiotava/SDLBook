#include"GameOverState.h"
#include"Game.h"
#include"TextureManager.h"
#include"AnimatedGraphic.h"
#include"MenuButton.h"
#include"MenuState.h"
#include"PlayState.h"

const std::string GameOverState::gameOverId = "GAMEOVER";

void GameOverState::gameOverToMain()
{
    TheGame::getInstance()->getStateMachine()->changeState(new MenuState());
}

void GameOverState::restartPlay()
{
    TheGame::getInstance()->getStateMachine()->changeState(new PlayState());
}

void GameOverState::update()
{
    for (int x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->update();
    }
}

void GameOverState::render()
{
    for (int x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->draw();
    }
}

bool GameOverState::onEnter()
{
    if (!TheTextureManager::getInstance()->load("assets/gameover.png", "gameovertext", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    if (!TheTextureManager::getInstance()->load("assets/main.png", "mainbutton", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    if (!TheTextureManager::getInstance()->load("assets/restart.png", "restartbutton", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "gameovertext"), 2);
    GameObject* buttonMainMenu = new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton"), gameOverToMain);
    GameObject* buttonRestart = new MenuButton(new LoaderParams(200, 300, 200, 80, "restartbutton"), restartPlay);

    gameObjects.push_back(gameOverText);
    gameObjects.push_back(buttonMainMenu);
    gameObjects.push_back(buttonRestart);

    std::cout << "entering GameOverState" << std::endl;

    return true;
}

bool GameOverState::onExit()
{
    std::cout << "exiting GameOverState" << std::endl;

    return true;
}
