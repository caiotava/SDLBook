//
// Created by caiotava on 4/28/21.
//

#include "BulletHandler.h"

#include "Game.h"

BulletHandler* BulletHandler::instance = 0;

BulletHandler * BulletHandler::Instance() {
    if (instance == 0) {
        instance = new BulletHandler();
    }

    return instance;
}

void BulletHandler::addPlayerBullet(int x, int y, int width, int height, std::string textureID, int numFrames,
                                    Vector2D heading) {
    PlayerBullet* bullet = new PlayerBullet();

    bullet->load(std::unique_ptr<LoaderParams>(new LoaderParams(x, y, width, height, textureID, numFrames)), heading);

    playerBullets.push_back(bullet);
}

void BulletHandler::addEnemyBullet(int x, int y, int width, int height, std::string textureID, int numFrames,
                                   Vector2D heading) {
    EnemyBullet* bullet = new EnemyBullet();

    bullet->load(std::unique_ptr<LoaderParams>(new LoaderParams(x, y, width, height, textureID, numFrames)), heading);

    enemyBullets.push_back(bullet);
}

void BulletHandler::updateBullets() {
    checkBullets(&playerBullets);
    checkBullets(reinterpret_cast<std::vector<PlayerBullet *> *>(&enemyBullets));
}

void BulletHandler::checkBullets(std::vector<PlayerBullet*> *bullets) {
    for (auto it = bullets->begin(); it != bullets->end();) {
        bool outXBounds = (*it)->getPosition().getX() < 0 || (*it)->getPosition().getX() > Game::Instance()->getGameWidth();
        bool outYBounds = (*it)->getPosition().getY() < 0 || (*it)->getPosition().getY() > Game::Instance()->getGameHeight();

        if (outXBounds || outYBounds || (*it)->isDead()) {
            delete *it;

            it = bullets->erase(it);
            continue;
        }

        (*it)->update();
        it++;
    }
}

void BulletHandler::drawBullets() {
    for (auto& b : playerBullets) {
        b->draw();
    }

    for (auto& b : enemyBullets) {
        b->draw();
    }
}

void BulletHandler::clearBullets() {
    playerBullets.clear();
    enemyBullets.clear();
}