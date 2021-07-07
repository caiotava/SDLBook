//
// Created by caiotava on 4/24/21.
//

#include "Game.h"
#include "GameObjectFactory.h"
#include "StateParser.h"
#include "TextureManager.h"

bool StateParser::parseState(const char *stateFile, std::string stateID, std::vector<GameObject *> *objects,
                             std::vector<std::string> *textures) {
    TiXmlDocument xmlDoc;

    if (!xmlDoc.LoadFile(stateFile)) {
        std::cerr << xmlDoc.ErrorDesc() << std::endl;
        return false;
    }

    TiXmlElement *root = xmlDoc.RootElement();
    TiXmlElement *stateRoot = 0;

    for (TiXmlElement *e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == stateID) {
            stateRoot = e;
            break;
        }
    }

    if (stateRoot == 0) {
        return false;
    }

    TiXmlElement *texturesRoot = 0;
    for (auto e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("textures")) {
            texturesRoot = e;
            break;
        }
    }

    parseTextures(texturesRoot, textures);

    TiXmlElement *objectsRoot = 0;
    for (auto e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        if (e->Value() == std::string("objects")) {
            objectsRoot = e;
        }
    }

    parseObjects(objectsRoot, objects);

    return true;
}

void StateParser::parseTextures(TiXmlElement *stateRoot, std::vector<std::string> *textures) {
    for (auto e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        std::string filename = e->Attribute("filename");
        std::string idAttribute = e->Attribute("id");

        textures->push_back(idAttribute);

        TextureManager::Instance()->load(filename, idAttribute, Game::Instance()->getRenderer());
    }
}

void StateParser::parseObjects(TiXmlElement *stateRoot, std::vector<GameObject *> *objects) {
    for (auto e = stateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        int x, y, width, height, numFrames, callbackID, animSpeed;
        std::string textureID, type;

        e->Attribute("x", &x);
        e->Attribute("y", &y);
        e->Attribute("width", &width);
        e->Attribute("height", &height);
        e->Attribute("numFrames", &numFrames);
        e->Attribute("callbackID", &callbackID);
        e->Attribute("animSpeed", &animSpeed);

        textureID = e->Attribute("textureID");
        type = e->Attribute("type");

        GameObject* object = GameObjectFactory::Instance()->create(type);

        object->load(new LoaderParams(x, y, width, height, textureID, numFrames, callbackID, animSpeed));

        objects->push_back(object);
    }
}