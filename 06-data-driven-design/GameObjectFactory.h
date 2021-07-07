//
// Created by caiotava on 4/24/21.
//

#ifndef SDLBOOK_CMAKE_GAMEOBJECTFACTORY_H
#define SDLBOOK_CMAKE_GAMEOBJECTFACTORY_H

#include "GameObject.h"
#include<map>
#include<string>

class BaseCreator {
public:
    virtual GameObject* createGameObject() const = 0;

    virtual ~BaseCreator() {}
};

class GameObjectFactory {
public:
    bool registerType(std::string typeID, BaseCreator* creator);
    GameObject* create(std::string typeID);

    static GameObjectFactory* Instance();

private:
    GameObjectFactory() {}
    std::map<std::string, BaseCreator*> creators;

    static GameObjectFactory* instance;
};


#endif //SDLBOOK_CMAKE_GAMEOBJECTFACTORY_H
