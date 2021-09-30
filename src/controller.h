#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "tetris.h"

class Command {
public:
    virtual ~Command() {}
    virtual void execute(Tetris *tetris) = 0;
};

class MoveLeftCommand : public Command {
public:
    virtual void execute(Tetris *tetris) { 
        tetris->getActivePiece()->MoveLeft(tetris->getPlayfield());
    }
};

class MoveRightCommand : public Command {
public:
    virtual void execute(Tetris *tetris) { 
        tetris->getActivePiece()->MoveRight(tetris->getPlayfield());

    }
};

class MoveDownCommand : public Command {
public:
    virtual void execute(Tetris *tetris) {
        tetris->getActivePiece()->MoveDown();
    }
};

class RotateCommand : public Command {
public:
    virtual void execute(Tetris *tetris) {
        tetris->getActivePiece()->Rotate(tetris->getPlayfield());
    }
};

class SlamCommand : public Command {
public:
    virtual void execute(Tetris *tetris) {
        tetris->getActivePiece()->Slam(tetris->getPlayfield());
    }
};

class SaveCommand : public Command {
public:
    virtual void execute(Tetris *tetris) {
        tetris->savePiece();
    }
};

class Controller {
public:
    Controller();
    void HandleInput(bool &running, Tetris &tetris);

private: 
    Command* UP_ARROW;
    Command* LEFT_ARROW;
    Command* RIGHT_ARROW;
    Command* DOWN_ARROW;
    Command* SPACE;
    Command* RIGHT_CTRL;
};




#endif /* CONTROLLER_H */