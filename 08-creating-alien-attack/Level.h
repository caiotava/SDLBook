//
// Created by caiotava on 4/25/21.
//

#ifndef SDLBOOK_CMAKE_LEVEL_H
#define SDLBOOK_CMAKE_LEVEL_H

#include "Player.h"
#include "TileLayer.h"
#include<string>
#include<vector>

struct TileSet {
    int firstGridID;
    int tileWidth;
    int tileHeight;
    int spacing;
    int margin;
    int width;
    int height;
    int numColumns;
    std::string name;
};

class Level {
public:
    void update();

    void render();

    std::vector<TileSet> *getTileSets() { return &tileSets; }

    std::vector<Layer *> *getLayers() { return &layers; }

    std::vector<Layer *> *getCollisions() { return &collisions; }

    Player *getPlayer() { return player; }

    void setPlayer(Player *p) { player = p; }

private:
    std::vector<TileSet> tileSets;
    std::vector<Layer *> layers;
    std::vector<TileLayer *> collisions;
    Player *player;
};

#endif //SDLBOOK_CMAKE_LEVEL_H
