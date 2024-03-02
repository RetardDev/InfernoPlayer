cmake_minimum_required(VERSION 3.26)
project(InfernoPlayer)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio)

add_executable(InfernoPlayer main.cpp
        MusicPlayer.h
        MusicPlayer.cpp
        Button.h
        Button.cpp
        FileDialog.h
        FileDialog.cpp)

target_link_libraries(InfernoPlayer sfml-graphics sfml-audio)