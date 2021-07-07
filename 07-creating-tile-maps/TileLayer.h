//
// Created by caiotava on 4/25/21.
//

#ifndef SDLBOOK_CMAKE_TILELAYER_H
#define SDLBOOK_CMAKE_TILELAYER_H

#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"

class TileLayer : public Layer {
public:
    TileLayer(int tileSize, const std::vector<TileSet> &tileSets);

    virtual void update();
    virtual void render();

    void setTileSize(int size) { tileSize = size; }
    void setTileIDs(const std::vector<std::vector<int>> &IDs) { tileIDs = IDs; }

    TileSet getTileSetByID(int tileID);

private:
    int tileSize;
    int numColumns;
    int numRows;

    Vector2D position;
    Vector2D velocity;

    const std::vector<TileSet> &tileSets;
    std::vector<std::vector<int>> tileIDs;
};


#endif //SDLBOOK_CMAKE_TILELAYER_H
