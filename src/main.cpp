#include <iostream>
#include <thread>
#include "renderer.h"
#include "game.h"
#include "controller.h"
#include "tetris.h"


/*
BUG LIST
O and Z clip other pieces when using SLAM **** UPDATE --> SLAM when a piece is about to go down causes clipping

When clearing multiple non contigious lines the shifted lines are not correctly calculated

*/
//TODO: DONE! WALL BUG USING PIECE ROTATION NEAR A WALL
    //TODO: ALLOW ROTATION IF IT CAN FIT AFTER SHIFTING AT LEAST 1 PLACE
//TODO: DONE! LINE COMPLETION CHECK AND ERASE
//TODO: DONE! LOSE CONDITION UPON FILLING UP
//TODO: LOSE OR VICTORY MESSAGE and score
//TODO: Clean debug output messages
//TODO: MUSIC
//TODO: DONE! Saving a piece
//TODO: UI show saved piece and next piece
//TODO: Add input controll from a file
//TODO: Add piece memory deallocation

int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kWindowWidth{460};
    constexpr std::size_t kWindowHeight{640};

    Renderer renderer(kWindowWidth,kWindowHeight);
    Controller controller;
    Game game;
    game.Run(controller, renderer, kMsPerFrame);
    
    return 0;
}