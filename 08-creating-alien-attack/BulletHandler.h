//
// Created by caiotava on 4/28/21.
//

#ifndef SDLBOOK_CMAKE_BULLETHANDLER_H
#define SDLBOOK_CMAKE_BULLETHANDLER_H

#include "Bullet.h"
#include<vector>

class BulletHandler {
public:
    static BulletHandler* Instance();

    void addPlayerBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading);

    void addEnemyBullet(int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading);

    void updateBullets();
    void drawBullets();

    void clearBullets();

private:

    BulletHandler() {}
    ~BulletHandler() {}

    void checkBullets(std::vector<PlayerBullet*> *bullets);

    static BulletHandler* instance;

    std::vector<PlayerBullet*> playerBullets;
    std::vector<EnemyBullet*> enemyBullets;
};


#endif //SDLBOOK_CMAKE_BULLETHANDLER_H
