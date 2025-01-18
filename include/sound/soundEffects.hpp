#ifndef SOUND
#define SOUND

#include <bits/stdc++.h>
#include <SFML/Audio.hpp>
using namespace sf;


class SoundEffects {
private:
    SoundBuffer boink;
    vector<Sound> active_sounds;
public:
    unordered_map<string, SoundBuffer> sound_effects;
    SoundEffects() {
        cout << "INITIALIZING SOUND EFFECTS" << endl;
        if(!boink.loadFromFile("audio/boink.wav")) {
            std::cerr << "Failed to load sound file!" << std::endl;
            return;
        }
        sound_effects["boink"] = boink;
    }
    void playSound(const string& sound_name) {
        cout << "PLAYING SOUND" << endl;
        if (sound_effects.find(sound_name) != sound_effects.end()) {
            Sound sound(sound_effects[sound_name]);
            active_sounds.push_back(sound);
            active_sounds.back().play();
        }
    }

    void cleanUp() {
        active_sounds.erase(remove_if(active_sounds.begin(), active_sounds.end(),
            [](const Sound& sound) { return sound.getStatus() == Sound::Status::Stopped; }),
                active_sounds.end());
    }
};


#endif