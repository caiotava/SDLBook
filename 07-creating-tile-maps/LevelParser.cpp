//
// Created by caiotava on 4/25/21.
//

#include "LevelParser.h"

#include "Game.h"
#include "GameObjectFactory.h"
#include "ObjectLayer.h"
#include "TextureManager.h"
#include "TileLayer.h"
#include "base64/base64.h"
#include "zlib.h"

std::string propertiesEl = "properties";
std::string propertyEl = "property";
std::string objectGroupEl = "objectgroup";
std::string tileSetEl = "tileset";
std::string layerEl = "layer";
std::string objectEl = "object";

Level *LevelParser::parseLevel(const char *levelFile) {
    TiXmlDocument levelDocument;
    levelDocument.LoadFile(levelFile);

    Level *level = new Level();

    TiXmlElement *root = levelDocument.RootElement();

    root->Attribute("tilewidth", &tileSize);
    root->Attribute("width", &width);
    root->Attribute("height", &height);

    for (auto e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == propertiesEl) {
            parseTextures(e);
        }

        if (e->Value() == tileSetEl) {
            parseTileSets(e, level->getTileSets());
        }

        if (e->Value() == objectGroupEl) {
            parseObjectLayer(e, level->getLayers());
        }

        if (e->Value() == layerEl) {
            parseTileLayer(e, level->getLayers(), level->getTileSets());
        }
    }

    return level;
}

void LevelParser::parseTileSets(TiXmlElement *tileSetRoot, std::vector<TileSet> *tileSets) {
    auto firstEl = tileSetRoot->FirstChildElement();

    TextureManager::Instance()->load(
            std::string("assets/") + std::string(firstEl->Attribute("source")),
            tileSetRoot->Attribute("name"),
            Game::Instance()->getRenderer()
    );

    TileSet tileSet;

    firstEl->Attribute("width", &tileSet.width);
    firstEl->Attribute("height", &tileSet.height);
    tileSetRoot->Attribute("firstgid", &tileSet.firstGridID);
    tileSetRoot->Attribute("tilewidth", &tileSet.tileWidth);
    tileSetRoot->Attribute("tileheight", &tileSet.tileHeight);
    tileSetRoot->Attribute("spacing", &tileSet.spacing);
    tileSetRoot->Attribute("margin", &tileSet.margin);

    tileSet.name = tileSetRoot->Attribute("name");
    tileSet.numColumns = tileSet.width / (tileSet.tileWidth + tileSet.spacing);

    tileSets->push_back(tileSet);
}

void LevelParser::parseTileLayer(TiXmlElement *titleElement, std::vector<Layer *> *layers,
                                 const std::vector<TileSet> *tileSets) {
    TileLayer *tileLayer = new TileLayer(tileSize, *tileSets);

    std::vector<std::vector<int>> data;

    std::string decodedIDs;
    TiXmlElement *dataNode;

    for (auto e = titleElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("data")) {
            dataNode = e;
            break;
        }
    }

    for (auto e = dataNode->FirstChild(); e != NULL; e = e->NextSibling()) {
        TiXmlText *text = e->ToText();
        std::string t = text->Value();
        decodedIDs = base64_decode(t);
    }

    uLongf numGIDs = width * height * sizeof(int);

    std::vector<unsigned> gids(numGIDs);

    uncompress((Bytef *) &gids[0], &numGIDs, (const Bytef *) decodedIDs.c_str(), decodedIDs.size());

    std::vector<int> layerRow(width);

    for (int i = 0; i < height; i++) {
        data.push_back(layerRow);
    }

    for (int rows = 0; rows < height; rows++) {
        for (int cols = 0; cols < width; cols++) {
            data[rows][cols] = gids[rows * width + cols];
        }
    }

    tileLayer->setTileIDs(data);
    layers->push_back(tileLayer);
}

void LevelParser::parseTextures(TiXmlElement *textureRoot) {
    for (auto p = textureRoot->FirstChildElement(); p != NULL; p = p->NextSiblingElement()) {
        if (p->Value() != propertyEl) {
            continue;
        }

        TextureManager::Instance()->load(
                p->Attribute("value"),
                p->Attribute("name"),
                Game::Instance()->getRenderer()
        );
    }
}

void LevelParser::parseObjectLayer(TiXmlElement *objectElement, std::vector<Layer *> *layers) {
    ObjectLayer *objectLayer = new ObjectLayer();

    std::cout << objectElement->FirstChildElement()->Value();

    for (auto e = objectElement->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() != objectEl) {
            continue;
        }

        int x, y, width, height, numFrames, callbackID, animSpeed;
        std::string textureID;

        e->Attribute("x", &x);
        e->Attribute("y", &y);

        GameObject *gameObject = GameObjectFactory::Instance()->create(e->Attribute("type"));

        for (auto ps = e->FirstChildElement(); ps != NULL; ps = ps->NextSiblingElement()) {
            if (ps->Value() != propertiesEl) {
                continue;
            }

            for (auto p = ps->FirstChildElement(); p != NULL; p = p->NextSiblingElement()) {
                if (p->Value() != propertyEl) {
                    continue;
                }

                if (p->Attribute("name") == std::string("numFrames")) {
                    p->Attribute("value", &numFrames);
                } else if (p->Attribute("name") == std::string("textureHeight")) {
                    p->Attribute("value", &height);
                } else if (p->Attribute("name") == std::string("textureWidth")) {
                    p->Attribute("value", &width);
                } else if (p->Attribute("name") == std::string("callbackID")) {
                    p->Attribute("value", &callbackID);
                } else if (p->Attribute("name") == std::string("animSpeed")) {
                    p->Attribute("value", &animSpeed);
                } else if (p->Attribute("name") == std::string("textureID")) {
                    textureID = p->Attribute("value");
                }
            }
        }

        gameObject->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));

        objectLayer->getGameObjects()->push_back(gameObject);
    }

    layers->push_back(objectLayer);
}