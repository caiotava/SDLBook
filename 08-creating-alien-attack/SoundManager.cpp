//
// Created by caiotava on 4/26/21.
//

#include "SoundManager.h"

#include<iostream>

SoundManager *SoundManager::instance = 0;

SoundManager::SoundManager() {
    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager() {
    Mix_CloseAudio();
}

bool SoundManager::load(std::string fileName, std::string id, sound_type type) {
    if (type == SOUND_MUSIC) {
        Mix_Music *song = Mix_LoadMUS(fileName.c_str());

        if (song == 0) {
            std::cout << "could not load music: " << Mix_GetError() << std::endl;
            return false;
        }

        music[id] = song;
        return true;
    }

    if (type == SOUND_SFX) {
        Mix_Chunk *chunk = Mix_LoadWAV(fileName.c_str());

        if (chunk == 0) {
            std::cout << "could not load sfx: " << Mix_GetError() << std::endl;
            return false;
        }

        sfxs[id] = chunk;
        return true;
    }

    return false;
}

void SoundManager::playSound(std::string id, int loop) {
    Mix_PlayChannel(-1, sfxs[id], loop);
}

void SoundManager::playMusic(std::string id, int loop) {
    Mix_PlayMusic(music[id], loop);
}