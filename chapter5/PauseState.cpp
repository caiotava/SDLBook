#include"PauseState.h"
#include"Game.h"
#include"MenuState.h"
#include"MenuButton.h"
#include"TextureManager.h"
#include"InputHandler.h"
#include"LoaderParams.h"

const std::string PauseState::pauseId = "PAUSE";

void PauseState::pauseToMain()
{
    TheGame::getInstance()->getGameStateMachine()->changeState(new MenuState());
}

void PauseState::resumePlay()
{
    TheGame::getInstance()->getGameStateMachine()->popState();
}

void PauseState::update()
{
    for (std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->update();
    }
}

void PauseState::render()
{
    for (std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->draw();
    }
}

bool PauseState::onEnter()
{
    TextureManager* textureManager = TheTextureManager::getInstance();

    if (!textureManager->load("assets/resume.png", "resumebutton", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    if (!textureManager->load("assets/main.png", "mainbutton", TheGame::getInstance()->getRenderer())) {
        return false;
    }

    GameObject* buttonMain = new MenuButton(new LoaderParams(200, 100, 200, 80, "mainbutton"), pauseToMain);
    GameObject* buttonResume = new MenuButton(new LoaderParams(200, 300, 200, 80, "resumebutton"), resumePlay);

    gameObjects.push_back(buttonMain);
    gameObjects.push_back(buttonResume);

    std::cout << "Entering PauseState" << std::endl;
    return true;
}

bool PauseState::onExit()
{
    for (std::vector<GameObject*>::size_type x = 0; x < gameObjects.size(); x++) {
        gameObjects[x]->clean();
    }

    gameObjects.clear();
    TheTextureManager::getInstance()->clearFromTextureMap("resumebutton");
    TheTextureManager::getInstance()->clearFromTextureMap("mainbutton");

    /* TheInputHandler::getInstance()->reset(); */

    std::cout << "exiting PauseState" << std::endl;

    return true;
}
