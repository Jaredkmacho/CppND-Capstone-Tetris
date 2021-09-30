#define VERBOSE

#include <iostream>
#include "renderer.h"
#include "game.h"
#include "controller.h"
#include "tetris.h"


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