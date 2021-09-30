#include <iostream>
#include "controller.h"

Controller::Controller() {
    UP_ARROW = new RotateCommand();
    RIGHT_ARROW = new MoveRightCommand();
    LEFT_ARROW = new MoveLeftCommand();
    DOWN_ARROW = new MoveDownCommand();
    SPACE = new SlamCommand();
    RIGHT_CTRL = new SaveCommand();
}

void Controller::HandleInput(bool &running, Tetris &tetris) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            running = false;
        } else if(e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                case SDLK_UP:
                    //TODO: Implement Rotate command
                    UP_ARROW->execute(&tetris);
                    //std::cout << "UP" << std::endl;
                    break;
                case SDLK_LEFT:
                    //TODO: Implement MoveLeft command
                    LEFT_ARROW->execute(&tetris);
                    //std::cout << "LEFT" << std::endl;
                    break;
                case SDLK_RIGHT:
                    //TODO: Implement MoveRight command
                    RIGHT_ARROW->execute(&tetris);
                    //std::cout << "RIGHT" << std::endl;
                    break;
                case SDLK_DOWN:
                    //TODO: Implement MoveRight command
                    DOWN_ARROW->execute(&tetris);
                    //std::cout << "DOWN" << std::endl;
                    break;
                case SDLK_SPACE:
                    //std::cout << "SPACE" << std::endl;
                    SPACE->execute(&tetris);
                    break;
                case SDLK_RCTRL:
                    //std::cout << "RCTRL" << std::endl;
                    RIGHT_CTRL->execute(&tetris);
                    break;

            }
            #ifdef VERBOSE
            std::cout << "Position now: X=" << tetris.getActivePiece()->getXPosition() << " Y=" << tetris.getActivePiece()->getYPosition() << std::endl;
            std::cout << "Orientation mode: " << tetris.getActivePiece()->getOrientation() << std::endl;
            #endif
        }
    }
}