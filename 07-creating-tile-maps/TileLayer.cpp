//
// Created by caiotava on 4/25/21.
//

#include "TileLayer.h"

#include "Game.h"

TileLayer::TileLayer(int tileSize, const std::vector<TileSet> &tileSets) :
        tileSize(tileSize),
        tileSets(tileSets),
        position(0, 0),
        velocity(0, 0) {
    numColumns = Game::Instance()->getGameWidth() / tileSize;
    numRows = Game::Instance()->getGameHeight() / tileSize;
}

void TileLayer::update() {
    position += velocity;
    velocity.setX(1);
}

void TileLayer::render() {
    int x, y, x2, y2 = 0;

    x = position.getX() / tileSize;
    y = position.getY() / tileSize;

    x2 = int(position.getX()) % tileSize;
    y2 = int(position.getY()) % tileSize;

    for (int i = 0; i < tileIDs.size(); i++) {
        for (int j = 0; j < numColumns; j++) {
            int id = tileIDs[i][j + x];

            if (id == 0) {
                continue;
            }

            TileSet tileSet = getTileSetByID(id);

            id--;

            TextureManager::Instance()->drawTile(
                    tileSet.name,
                    tileSet.margin,
                    tileSet.spacing,
                    (j * tileSize) -x2,
                    (i * tileSize) - y2,
                    tileSize,
                    tileSize,
                    (id - (tileSet.firstGridID - 1)) / tileSet.numColumns,
                    (id - (tileSet.firstGridID - 1)) % tileSet.numColumns,
                    Game::Instance()->getRenderer()
            );
        }
    }
}

TileSet TileLayer::getTileSetByID(int tileID) {
    for (int i = 0; i < tileSets.size(); i++) {
        if (i + 1 <= tileSets.size() -1) {
            if (tileID >= tileSets[i].firstGridID && tileID < tileSets[i + 1].firstGridID) {
                return tileSets[i];
            }
        } else {
            return tileSets[i];
        }
    }

    std::cout << "did not find tile set, returning empty tile set" << std::endl;

    TileSet t;
    return t;
}