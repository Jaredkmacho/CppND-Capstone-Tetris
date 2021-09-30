#ifndef GAME_H
#define GAME_H

#include <random>
#include "tetris.h"
#include "renderer.h"
#include "controller.h"

class Game {
public:
    Game();
    void Run(Controller &controller, Renderer &renderer, 
                std::size_t target_frame_duration);

private:
    Tetris tetris;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> rdm_orientation;
    std::uniform_int_distribution<int> rdm_piece;

    void Update();
};


#endif /* GAME_H */