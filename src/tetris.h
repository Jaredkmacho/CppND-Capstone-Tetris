#ifndef TETRIS_H
#define TETRIS_H

#include <vector>
#include <random>
#include <memory>
#include <SDL2/SDL.h>
#include "tetris_pieces.h"

class Playfield;

enum TETRIS_STATUS {
    PIECE_ACTIVE,
    PIECE_PLACED,
    PIECE_FIT,
    PIECE_BLOCKED
};

enum TETRIS_PIECE {
    I,
    J,
    L,
    O,
    S,
    T,
    Z
};

class Piece {
public:
    virtual ~Piece();
    std::vector<int> getSprite() const { return sprite_; } 
    int getXPosition() { return Xposition_; }
    int getYPosition() { return Yposition_; }
    SDL_Color getColor() { return color_; }
    int getOrientation() { return orientation_; }
    void Slam(Playfield *playfield);
    void MoveRight(Playfield *playfield);
    void MoveLeft(Playfield *playfield);
    void MoveDown();
    void Rotate(Playfield *playfield);
    void setSpeed(int speed) { speed_ = speed; }
    bool evaluatePlace(Playfield *playfield);
    void Save() { saved_ = true; };
    bool isSaved() { return saved_; }
    int getType() { return type_; }
    virtual TETRIS_STATUS Update(Playfield *playfield);

    int cell_id_[4];
    
private:
    virtual void setSprite(int mode) = 0;
    bool ShiftRight(Playfield *playfield);
    bool ShiftLeft(Playfield *playfield);

protected:
    int type_;
    bool saved_;
    int Xposition_;
    int speed_;
    int Yposition_;
    int Ydelay;
    SDL_Color color_;
    int orientation_;
    std::vector<int> sprite_;
    int sprite_width;
};

class I_Piece : public Piece {
public: 
    I_Piece(int pfWidth);
private:
    void setSprite(int mode);
};

class J_Piece : public Piece {
public: 
    J_Piece(int pfWidth);
private:
    void setSprite(int mode);
};

class L_Piece : public Piece {
public: 
    L_Piece(int pfWidth);
private:
    void setSprite(int mode);
};

class O_Piece : public Piece {
public: 
    O_Piece(int pfWidth);
private:
    void setSprite(int mode);
};

class S_Piece : public Piece {
public: 
    S_Piece(int pfWidth);
private:
    void setSprite(int mode);
};

class T_Piece : public Piece {
public: 
    T_Piece(int pfWidth);
private:
    void setSprite(int mode);
};

class Z_Piece : public Piece {
public: 
    Z_Piece(int pfWidth);
private:
    void setSprite(int mode);
};

class Spawner
{
public:
    virtual ~Spawner() {}
    virtual Piece* spawnPiece(int pfWidth) = 0;
};

template <class T>
class SpawnerFor : public Spawner {
public:
    virtual Piece* spawnPiece(int pfWidth) { return new T(pfWidth); };
};



class PlayfieldCell {
public:
    PlayfieldCell(int width);
    PlayfieldCell(int width, int index);
    void setCellIndex(int index) { index_ = index; }
    void setCellPosition(SDL_Point position);
    bool getCellStatus() { return ocupied_; }
    void setCellStatus(bool status) { ocupied_ = status; }
    SDL_Rect getCellBox() { return cell_; }
    void setCellColor(SDL_Color nColor) { color_ = nColor; }
    SDL_Color getCellColor() { return color_; }
    PlayfieldCell &operator<<(PlayfieldCell &source);
    void Clear();

private:
    bool ocupied_ = false;
    int index_;
    SDL_Rect cell_;
    SDL_Color color_;
};

class Playfield {
public:
    Playfield() {};
    Playfield(SDL_Point pOrigin);
    ~Playfield();
    // Playfield(const Playfield &source);

    void getPlayfieldBox(SDL_Point *outBox, SDL_Point *inBox);
    void getPlayfieldCells(SDL_Rect *cells, SDL_Color *color);
    TETRIS_STATUS evaluateActivePiece(Piece *piece);
    virtual void colorPiece(Piece *piece);
    virtual void clearActivePiece(Piece *piece);
    void placeActivePiece(Piece *piece);
    bool checkCellCollision(int id) {return id >= getNumberOfCells() || cells_[id].getCellStatus(); };
    int getPlayfieldWidth() { return playfield_width_; }
    int getNumberOfCells() { return playfield_width_ * playfield_height_; }
    void clearLine(int line);
    int Update(Piece *piece);

protected:
    virtual void generatePlayfield(SDL_Point pOrigin);
    virtual void generatePlayfieldCells(SDL_Point pOrigin);

    std::vector<SDL_Point> playfield_outbox_;
    std::vector<SDL_Point> playfield_inbox_;
    std::vector<PlayfieldCell> cells_;


    int playfield_width_ = 10;
    int playfield_height_ = 21;
    int cell_size_ = 28;

};

class Sidefield : public Playfield {
public:
    Sidefield(SDL_Point pOrigin);
    ~Sidefield() {}

    virtual void colorPiece(Piece *piece);
    void clearField();

private:

    const int sidefield_width_ = 4;
    const int sidefield_height_ = 4;
    const int sidecell_size_ = 20;
};

class Tetris {
public: 
    Tetris();
    ~Tetris();

    Playfield* getPlayfield() const {return playfield_.get();}
    Sidefield* getNextfield() const {return next_field_.get();}
    Sidefield* getSavedfield() const {return saved_field_.get();}
    Piece* getActivePiece() {return activePiece_;}
    int getLinesCleared() { return linesCleared; }
    void savePiece();
    void spawnPiece();
    void spawnPiece(int type);
    void Update(bool &running);
    

private: 

    std::shared_ptr<Playfield> playfield_;
    std::shared_ptr<Sidefield> next_field_;
    std::shared_ptr<Sidefield> saved_field_;
    Piece* activePiece_ = nullptr;
    Spawner* pieceSpawner_[7];
    int linesCleared = 0;

    int nextType_;
    int saveType_;
    bool savedPiece_ = false;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> rdm_orientation;
    std::uniform_int_distribution<int> rdm_piece;

};

#endif