//
// Created by cryptic on 28/02/24.
//

#include "MusicPlayer.h"
#include <iostream>
MusicPlayer::MusicPlayer()
    :fontPos("/home/cryptic/Documents/InfernoPlayer/arial.ttf"),
    font(),  // Initialize font here
    myButton(100, 100, 200, 50, fontPos, "Click me!"), playerState(mainMenu){

    initVariables();
    initWindow();

//    fontPos =  "/home/cryptic/Documents/InfernoPlayer/GreenKingsWood-Regular1.otf";
 //  font.loadFromFile(fontPos);
}

MusicPlayer::~MusicPlayer() {
    delete this->window;
}

void MusicPlayer::initVariables() {
    this->window= nullptr;
  //  myButton = Button(100, 100, 200, 50, font, "Click me!");
}

void MusicPlayer::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(videoMode, "Inferno Player", sf::Style::Default);
}

void MusicPlayer::pollEvents() {
    while(this->window->pollEvent(this->event)){
        if(this->event.type == sf::Event::Closed){
            this->window->close();
           break;
        }else if(this->event.type == sf::Event::KeyPressed){
            if(this->event.key.code == sf::Keyboard::Escape){
                this->window->close();
                break;
            }
        }else if(this->event.type == sf::Event::MouseButtonPressed && playerState == mainMenu){
            if(myButton.isMouseOver(*window)){
                musicPos = uploadMusic();
                playMusic(musicPos);
                playerState = playing;
            }
        }
//        switch(this->event.type){
//            case sf::Event::Closed:
//
//                break;
//            case sf::Event::KeyPressed:
//                if(this->event.key.code == sf::Keyboard::Escape)
//                {
//                    this->window->close();
//                    break;
//                }
//            case sf::Event::MouseButtonPressed && playerState == mainMenu:
//                if(myButton.isMouseOver(*window)){
//                    std::cout << "clicked";
//                }
//        }
    }
}

void MusicPlayer::update() {
    this->pollEvents();
}




void MusicPlayer::render() {
    this->window->clear();
    if(playerState == mainMenu) {
        myButton.draw(*window);
    }
    this->window->display();
}

const bool MusicPlayer::running() const {
    return this->window->isOpen();
}

void MusicPlayer::menu() {

}

std::string MusicPlayer::uploadMusic() {
    FileDialog f1;
    return f1.openFile();
}

void MusicPlayer::playMusic(std::string musicPos) {

    if(!music.openFromFile(musicPos)){
        std::cerr << "error loading music";
    }
    music.play();
//    sf::SoundBuffer buffer;
//    sf::Sound sound;
//    if(!buffer.loadFromFile(musicPos)){
//        std::cerr << "error loading music";
//    }
//    sound.setBuffer(buffer);
//    sound.play();


}

