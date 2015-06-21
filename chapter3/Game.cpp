#include<iostream>
#include "Game.h"
#include"TextureManager.h"
#include"Player.h"
#include"Enemy.h"

bool Game::init(const char *title, int xPosition, int yPosition, int height, int width, bool fullScreen)
{
    int flags = SDL_WINDOW_SHOWN;

    if (fullScreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, xPosition, yPosition, height, width, flags);

    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == nullptr) {
        return false;
    }

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    TheTextureManager::getInstance()->load("assets/animate-alpha.png", "animate", renderer);

    GameObject *gameObject = new GameObject();
    GameObject *player = new Player();
    GameObject *enemy = new Enemy();

    gameObject->load(100, 100, 128, 82, "animate");
    player->load(300, 300, 128, 82, "animate");
    enemy->load(0, 0, 128, 82, "animate");

    gameObjects.push_back(gameObject);
    gameObjects.push_back(player);
    gameObjects.push_back(enemy);

    running = true;
    return nullptr;
}

void Game::render()
{
    SDL_RenderClear(renderer);

    for (std::vector<GameObject*>::size_type x = 0; x != gameObjects.size(); x++) {
        gameObjects[x]->draw(renderer);
    }

    TheTextureManager::getInstance()->draw("animate", 0, 0, 128, 82, renderer);
    TheTextureManager::getInstance()->drawFrame("animate", 100, 100, 128, 82, 1, currentFrame, renderer);

    SDL_RenderPresent(renderer);
}

void Game::handleEvents()
{
    SDL_Event event;

    if (!SDL_PollEvent(&event)) {
        return;
    }

    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    for (std::vector<GameObject*>::size_type x = 0; x != gameObjects.size(); x++) {
        gameObjects[x]->update();
    }

    currentFrame = int((SDL_GetTicks() / 100) % 6);

    SDL_Delay(10);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
