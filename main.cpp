#include <iostream>
#include <SFML/Audio.hpp>
#include "MusicPlayer.h"
int main() {
    MusicPlayer mp;
    while(mp.running()){
        mp.update();
        mp.render();
    }
    return 0;
}
