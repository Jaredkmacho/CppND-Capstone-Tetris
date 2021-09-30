#include <iostream>
#include <thread>
#include "renderer.h"
#include "game.h"
#include "controller.h"
#include "tetris.h"
#include <string>
#include <sstream>

/*
BUG LIST
O and Z clip other pieces when using SLAM **** UPDATE --> SLAM when a piece is about to go down causes clipping

*/
//TODO: DONE! WALL BUG USING PIECE ROTATION NEAR A WALL
    //TODO: ALLOW ROTATION IF IT CAN FIT AFTER SHIFTING AT LEAST 1 PLACE
//TODO: DONE! LINE COMPLETION CHECK AND ERASE
//TODO: LOSE CONDITION UPON FILLING UP
//TODO: MUSIC
//TODO: SAVING A PIECE

int main() {
    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

    Renderer renderer(640,640);
    Controller controller;
    Game game;
    game.Run(controller, renderer, kMsPerFrame);
    
    return 0;
}