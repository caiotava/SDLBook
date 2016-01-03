#include"PauseState.h"
#include"Game.h"
#include"MenuState.h"
#include"MenuButton.h"
#include"TextureManager.h"
#include"InputHandler.h"

const std::string PauseState::pauseId = "PAUSE";

void PauseState::pauseToMain()
{
    TheGame::getInstance()->getStateMachine()->changeState(new MenuState());
}

void PauseState::resumePlay()
{
    TheGame::getInstance()->getStateMachine()->popState();
}

void PauseState::update()
{
    for (int x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->update();
    }
}

void PauseState::render()
{
    for (int x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->draw();
    }
}

bool PauseState::onEnter()
{
    if (!TheTextureManager::getInstance()->load("assets/resume.png", "resumebutton", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    if (!TheTextureManager::getInstance()->load("assets/main.png", "mainbutton", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    GameObject* buttonMain = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton"), pauseToMain);
    GameObject* buttonResume = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton"), resumePlay);

    gameObjects.push_back(buttonMain);
    gameObjects.push_back(buttonResume);

    std::cout << "entering PauseState" << std::endl;

    return true;
}

bool PauseState::onExit()
{
    for (int x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->clean();
    }

    gameObjects.clear();

    TheTextureManager::getInstance()->clearFromTextureMap("resumebutton");
    TheTextureManager::getInstance()->clearFromTextureMap("mainbutton");

    std::cout << "exiting PauseState" << std::endl;

    return true;
}
