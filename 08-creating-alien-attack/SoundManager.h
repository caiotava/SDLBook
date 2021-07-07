//
// Created by caiotava on 4/26/21.
//

#ifndef SDLBOOK_CMAKE_SOUNDMANAGER_H
#define SDLBOOK_CMAKE_SOUNDMANAGER_H

#include<SDL_mixer.h>
#include<string>
#include<map>

enum sound_type {
    SOUND_MUSIC = 0,
    SOUND_SFX = 1
};

class SoundManager {
public:
    static SoundManager *Instance() {
        if (instance == 0) {
            instance = new SoundManager();
        }

        return instance;
    }

    bool load(std::string fileName, std::string id, sound_type type);

    void playSound(std::string id, int loop);

    void playMusic(std::string id, int loop);

private:
    static SoundManager *instance;

    std::map<std::string, Mix_Chunk *> sfxs;
    std::map<std::string, Mix_Music *> music;

    SoundManager();

    ~SoundManager();
};


#endif //SDLBOOK_CMAKE_SOUNDMANAGER_H
