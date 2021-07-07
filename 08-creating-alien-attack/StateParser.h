//
// Created by caiotava on 4/24/21.
//

#ifndef SDLBOOK_CMAKE_STATEPARSER_H
#define SDLBOOK_CMAKE_STATEPARSER_H

#include "GameObject.h"
#include<iostream>
#include<tinyxml/tinyxml.h>
#include<vector>

class StateParser {
public:
    bool parseState(const char *stateFile, std::string stateID, std::vector<GameObject *> *objects,
                    std::vector<std::string> *textures);

private:
    void parseObjects(TiXmlElement *stateRoot, std::vector<GameObject *> *objects);

    void parseTextures(TiXmlElement *stateRoot, std::vector<std::string> *textures);
};


#endif //SDLBOOK_CMAKE_STATEPARSER_H
