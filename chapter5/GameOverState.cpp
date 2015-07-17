#include"GameOverState.h"
#include"Game.h"
#include"TextureManager.h"
#include"MenuState.h"
#include"PlayState.h"
#include"MenuButton.h"
#include"AnimatedGraphic.h"

const std::string GameOverState::gameOverId = "GAMEOVER";

void GameOverState::update()
{
    for (std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->update();
    }
}

void GameOverState::render()
{
    for (std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->draw();
    }
}
void GameOverState::gameOverToMain()
{
    TheGame::getInstance()->getGameStateMachine()->changeState(new MenuState());
}

void GameOverState::restartPlay()
{
    TheGame::getInstance()->getGameStateMachine()->changeState(new PlayState());
}

bool GameOverState::onEnter()
{
    Game* game = TheGame::getInstance();
    TextureManager*  textureManager = TheTextureManager::getInstance();

    if (!textureManager->load("assets/gameover.png", "gameovertext", game->getRenderer())) {
        return false;
    }

    if (!textureManager->load("assets/main.png", "mainbutton", game->getRenderer())) {
        return false;
    }

    if (!textureManager->load("assets/restart.png", "restartbutton", game->getRenderer())) {
        return false;
    }

    GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "gameovertext"), 2);
    GameObject* mainButton = new MenuButton(new LoaderParams(200, 200, 200, 80, "mainbutton"), gameOverToMain);
    GameObject* restartButton = new MenuButton(new LoaderParams(200, 300, 200, 80, "restartbutton"), restartPlay);

    gameObjects.push_back(gameOverText);
    gameObjects.push_back(mainButton);
    gameObjects.push_back(restartButton);

    std::cout << "Entering GameOverState" << std::endl;
    return true;
}

bool GameOverState::onExit()
{
    return true;
}
