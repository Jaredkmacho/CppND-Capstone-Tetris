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

    void Update(bool &running);
};


#endif /* GAME_H */