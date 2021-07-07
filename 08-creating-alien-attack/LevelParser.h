//
// Created by caiotava on 4/25/21.
//

#ifndef SDLBOOK_CMAKE_LEVELPARSER_H
#define SDLBOOK_CMAKE_LEVELPARSER_H

#include "Level.h"
#include "tinyxml/tinyxml.h"
#include<vector>

class TileLayer;

class LevelParser {
public:
    Level *parseLevel(const char *levelFile);

private:
    void parseTileSets(TiXmlElement *tileSetRoot, std::vector<TileSet> *tileSets);

    void parseTileLayer(TiXmlElement *titleElement, std::vector<Layer *> *layers, const std::vector<TileSet> *tileSets);

    void parseTextures(TiXmlElement *textureRoot);

    void parseObjectLayer(TiXmlElement *objectElement, std::vector<Layer*> *layers);

    int tileSize;
    int width;
    int height;
};


#endif //SDLBOOK_CMAKE_LEVELPARSER_H
