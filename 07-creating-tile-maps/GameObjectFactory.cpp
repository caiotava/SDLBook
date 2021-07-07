//
// Created by caiotava on 4/24/21.
//

#include "GameObjectFactory.h"

GameObjectFactory* GameObjectFactory::instance = 0;

GameObjectFactory *GameObjectFactory::Instance() {
    if (instance == 0) {
        instance = new GameObjectFactory();
    }

    return instance;
}

bool GameObjectFactory::registerType(std::string typeID, BaseCreator *creator) {
    auto it = creators.find(typeID);

    if (it != creators.end()) {
        delete creator;
        return false;
    }

    creators[typeID] = creator;

    return true;
}

GameObject *GameObjectFactory::create(std::string typeID) {
    auto it = creators.find(typeID);

    if (it == creators.end()) {
        std::cout << "could not find type: " << typeID << std::endl;
        return NULL;
    }

    BaseCreator *creator = it->second;

    return creator->createGameObject();
}