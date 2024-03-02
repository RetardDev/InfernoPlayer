//
// Created by cryptic on 28/02/24.
//

#ifndef INFERNOPLAYER_MUSICPLAYER_H
#define INFERNOPLAYER_MUSICPLAYER_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <filesystem>
#include "FileDialog.h"
#include <SFML/Audio.hpp>
class MusicPlayer {
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;
    std::string fontPos;
    sf::Font font;
    Button myButton;
    enum state{mainMenu, playing};
    state playerState;
    std::string musicPos;
    sf::Music music;

    void pollEvents();
    void initVariables();
    std::string uploadMusic();
    void playMusic(std::string musicPos);

public:
    MusicPlayer();
    ~MusicPlayer();
    void initWindow();
    void update();
    void render();

    void menu();


    const bool running() const;
};


#endif //INFERNOPLAYER_MUSICPLAYER_H
