
#include <cmath>
#include <algorithm>
#include <iostream>
#include "tetris.h"


Piece::~Piece() {}

void I_Piece::setSprite(int mode) {
    if(!sprite_.empty()) sprite_.clear();
    for(int i = 0; i < 16; i++) {
        switch (mode) 
        {
        case 0:
            sprite_.emplace_back(kImode0[i]);
            sprite_width = 4;
            break;
        case 1:
            sprite_.emplace_back(kImode1[i]);
            sprite_width = 1;
            break;
        case 2:
            sprite_.emplace_back(kImode2[i]);
            sprite_width = 4;
            break;
        case 3:
            sprite_.emplace_back(kImode3[i]);
            sprite_width = 1;
            break;
        default:
            break;
        }
    }
}

void J_Piece::setSprite(int mode) {
    
    if(!sprite_.empty()) {
        sprite_.clear();
        std::vector<int>().swap(sprite_);
    }
    for(int i = 0; i < 9; i++) {
        switch (mode) 
        {
        case 0:
            sprite_.emplace_back(kJmode0[i]);
            sprite_width = 3;
            break;
        case 1:
            sprite_.emplace_back(kJmode1[i]);
            sprite_width = 2;
            break;
        case 2:
            sprite_.emplace_back(kJmode2[i]);
            sprite_width = 3;
            break;
        case 3:
            sprite_.emplace_back(kJmode3[i]);
            sprite_width = 2;
            break;
        default:
            break;
        }
    }
}

void L_Piece::setSprite(int mode) {
    if(!sprite_.empty()) sprite_.clear();
    for(int i = 0; i < 9; i++) {
        switch (mode) 
        {
        case 0:
            sprite_.emplace_back(kLmode0[i]);
            sprite_width = 3;
            break;
        case 1:
            sprite_.emplace_back(kLmode1[i]);
            sprite_width = 2;
            break;
        case 2:
            sprite_.emplace_back(kLmode2[i]);
            sprite_width = 3;
            break;
        case 3:
            sprite_.emplace_back(kLmode3[i]);
            sprite_width = 2;
            break;
        default:
            break;
        }
    }
}

void O_Piece::setSprite(int mode) {
    if(!sprite_.empty()) sprite_.clear();
    for(int i = 0; i < 16; i++) {
        switch (mode) 
        {
        case 0:
            sprite_.emplace_back(kOmode0[i]);
            sprite_width = 2;
            break;
        case 1:
            sprite_.emplace_back(kOmode1[i]);
            sprite_width = 2;
            break;
        case 2:
            sprite_.emplace_back(kOmode2[i]);
            sprite_width = 2;
            break;
        case 3:
            sprite_.emplace_back(kOmode3[i]);
            sprite_width = 2;
            break;
        default:
            break;
        }
    }
}

void S_Piece::setSprite(int mode) {
    if(!sprite_.empty()) sprite_.clear();
    for(int i = 0; i < 9; i++) {
        switch (mode) 
        {
        case 0:
            sprite_.emplace_back(kSmode0[i]);
            sprite_width = 3;
            break;
        case 1:
            sprite_.emplace_back(kSmode1[i]);
            sprite_width = 2;
            break;
        case 2:
            sprite_.emplace_back(kSmode2[i]);
            sprite_width = 3;
            break;
        case 3:
            sprite_.emplace_back(kSmode3[i]);
            sprite_width = 2;
            break;
        default:
            break;
        }
    }
}

void T_Piece::setSprite(int mode) {
    if(!sprite_.empty()) sprite_.clear();
    for(int i = 0; i < 9; i++) {
        switch (mode) 
        {
        case 0:
            sprite_.emplace_back(kTmode0[i]);
            sprite_width = 3;
            break;
        case 1:
            sprite_.emplace_back(kTmode1[i]);
            sprite_width = 2;
            break;
        case 2:
            sprite_.emplace_back(kTmode2[i]);
            sprite_width = 3;
            break;
        case 3:
            sprite_.emplace_back(kTmode3[i]);
            sprite_width = 2;
            break;
        default:
            break;
        }
    }
}

void Z_Piece::setSprite(int mode) {
    if(!sprite_.empty()) sprite_.clear();
    for(int i = 0; i < 9; i++) {
        switch (mode) 
        {
        case 0:
            sprite_.emplace_back(kZmode0[i]);
            sprite_width = 3;
            break;
        case 1:
            sprite_.emplace_back(kZmode1[i]);
            sprite_width = 2;
            break;
        case 2:
            sprite_.emplace_back(kZmode2[i]);
            sprite_width = 3;
            break;
        case 3:
            sprite_.emplace_back(kZmode3[i]);
            sprite_width = 2;
            break;
        default:
            break;
        }
    }
}

I_Piece::I_Piece(int pfWidth) {
    type_ = TETRIS_PIECE::I;
    Ydelay = 0;
    orientation_ = 0;
    Xposition_ = pfWidth / 2 - 2;
    Yposition_ = 0;
    setSprite(orientation_);  

    color_ = {0x00, 0xFF, 0xFF, 0x1E}; 
}

J_Piece::J_Piece(int pfWidth) {
    type_ = TETRIS_PIECE::J;
    Ydelay = 0;
    orientation_ = 0;
    Xposition_ = pfWidth / 2 - 1;
    Yposition_ = 0;
    setSprite(orientation_);  

    color_ = {0x20, 0x20, 0xFF, 0x1E};
}

L_Piece::L_Piece(int pfWidth) {
    type_ = TETRIS_PIECE::L;
    Ydelay = 0;
    orientation_ = 0;
    Xposition_ = pfWidth / 2 - 1;
    Yposition_ = 0;
    setSprite(orientation_);  

    color_ = {0xFF, 0x80, 0x00, 0x1E};
}

O_Piece::O_Piece(int pfWidth) {
    type_ = TETRIS_PIECE::O;
    Ydelay = 0;
    orientation_ = 0;
    Xposition_ = pfWidth / 2 - 2;
    Yposition_ = 0;
    setSprite(orientation_);  

    color_ = {0xFF, 0xFF, 0x00, 0x1E};
}

S_Piece::S_Piece(int pfWidth) {
    type_ = TETRIS_PIECE::S;
    Ydelay = 0;
    orientation_ = 0;
    Xposition_ = pfWidth / 2 - 1;
    Yposition_ = 0;
    setSprite(orientation_);

    color_ = {0x00, 0xFF, 0x00, 0x1E};
}

T_Piece::T_Piece(int pfWidth) {
    type_ = TETRIS_PIECE::T;
    Ydelay = 0;
    orientation_ = 0;
    Xposition_ = pfWidth / 2 - 1;
    Yposition_ = 0;
    setSprite(orientation_);  

    color_ = {0x7F, 0x00, 0xFF, 0x1E};
}

Z_Piece::Z_Piece(int pfWidth) {
    type_ = TETRIS_PIECE::Z;
    Ydelay = 0;
    orientation_ = 0;
    Xposition_ = pfWidth / 2 - 1;
    Yposition_ = 0;
    setSprite(orientation_);  

    color_ = {0xFF, 0x00, 0x00, 0x1E};
}

void Piece::MoveLeft(Playfield *playfield) {
    int Xrange;
    for(int id : cell_id_) {
        Xrange = id % playfield->getPlayfieldWidth();
        if(playfield->checkCellCollision(id-1) || Xrange-1 < 0) 
            return;

    }
    Xposition_--;
}

void Piece::MoveRight(Playfield *playfield) {
    int Xrange;
    for(int id : cell_id_) {
        Xrange = id % playfield->getPlayfieldWidth();
        if(playfield->checkCellCollision(id+1) || playfield->getPlayfieldWidth() <= Xrange+1) 
            return;
    }
    Xposition_++;
}

bool Piece::ShiftLeft(Playfield *playfield) {
    int Xrange;
    for(int id : cell_id_) {
        Xrange = id % playfield->getPlayfieldWidth();
        if(playfield->checkCellCollision(id-1) || Xrange-1 < 0) 
            return false;

    }
    Xposition_--;
    TETRIS_STATUS ret = playfield->evaluateActivePiece(this);
    if(ret == TETRIS_STATUS::PIECE_BLOCKED) return false;
    return true;
}

bool Piece::ShiftRight(Playfield *playfield) {
    int Xrange;
    for(int id : cell_id_) {
        Xrange = id % playfield->getPlayfieldWidth();
        if(playfield->checkCellCollision(id+1) || playfield->getPlayfieldWidth() <= Xrange+1) 
            return false;
    }
    Xposition_++;
    TETRIS_STATUS ret = playfield->evaluateActivePiece(this);
    if(ret == TETRIS_STATUS::PIECE_BLOCKED) return false;
    return true;
}

void Piece::MoveDown() {
    Ydelay += 60;
}

void Piece::Slam(Playfield *playfield) {
    bool contact = false;
    int tmp{0}, index{0};
    int row[4] = {1, 1, 1, 1};
    for(int id: cell_id_) {
        tmp = id + playfield->getPlayfieldWidth();
        while(!contact) {
            if(playfield->checkCellCollision(tmp)) {
                contact = true;
                index++;
            } 
            else {
                tmp += playfield->getPlayfieldWidth();
                row[index]++;
            }
        }
        contact = false;
    }
    tmp = row[0];
    for (int i : row) 
        if (i < tmp) tmp = i;
    
    Yposition_ += tmp - 1;
    Update(playfield);
}

void Piece::Rotate(Playfield *playfield) {
    playfield->clearActivePiece(this);
    if(++orientation_ >= 4) 
        orientation_ = 0;
    setSprite(orientation_);

    TETRIS_STATUS ret = playfield->evaluateActivePiece(this);
    if(ret == TETRIS_STATUS::PIECE_BLOCKED) {
        //std::cout << "BLOCKED ROTATION" << std::endl; //debug stuff
        if(--orientation_ < 0) 
            orientation_ = 3;
        setSprite(orientation_);
    } else if (ret == TETRIS_STATUS::PIECE_FIT) {
        //Check if rotation clips a wall, if true rotate back
        //std::cout << "PIECE FIT" << std::endl; //debug stuff
        int tmp[4];
        for(int i = 0; i < 4; i++) {
            tmp[i] = cell_id_[i] % playfield->getPlayfieldWidth();
            //std::cout << "tmp " << i << " = "<< tmp[i] << std::endl; //debug stuff
        }
        int it = 0;
        bool split = false;
        while(it < 4) {
            for(int i = 0; i < 4; i++) {
                split = abs(tmp[it] - tmp[i]) >= sprite_width;
                //std::cout << "dif " << it << " = "<< abs(tmp[it] - tmp[i]) << std::endl; //debug stuff
            }
            if(split) break;
            ++it;
        }
        if(split) {
            //std::cout << "SPLIT ROTATION" << std::endl; //debug stuff
            //TODO: Check if rotation fits after shifing to the side.
            // if( ShiftLeft(playfield) ) return;
            // if( ShiftRight(playfield) ) return;
            if(--orientation_ < 0) 
                orientation_ = 3;
            setSprite(orientation_);
        }
    }
}

bool Piece::evaluatePlace(Playfield *playfield) {
    for(int id : cell_id_) {
        if(playfield->checkCellCollision( id + playfield->getPlayfieldWidth() ))
            return true;
    }
    return false;
}


TETRIS_STATUS Piece::Update(Playfield *playfield) {

    Ydelay += speed_;
    if(Ydelay > 60) {
        if(evaluatePlace(playfield)) {
            playfield->colorPiece(this);
            playfield->placeActivePiece(this);
            return PIECE_PLACED;
        } else {
            Yposition_++;
            Ydelay = 0;
        }
    }
    return PIECE_ACTIVE;
}



PlayfieldCell::PlayfieldCell(int width) {
    cell_.w = width - 2;
    cell_.h = width - 2;

    color_ = {0x50, 0x50, 0x50, 0xFF};
}

PlayfieldCell::PlayfieldCell(int width, int index) : index_(index) {
    cell_.w = width - 2;
    cell_.h = width - 2;
    
    color_ = {0x50, 0x50, 0x50, 0xFF};
}

void PlayfieldCell::setCellPosition(SDL_Point position) {
    cell_.x = position.x+1;
    cell_.y = position.y+1;
}

PlayfieldCell &PlayfieldCell::operator<<(PlayfieldCell &source) {
    color_ = source.color_;
    ocupied_ = source.ocupied_;

    return *this;
}

void PlayfieldCell::Clear() {
    color_ = {0x50, 0x50, 0x50, 0xFF};
    ocupied_ = false;
}


Playfield::Playfield(SDL_Point pOrigin) {
    generatePlayfield(pOrigin);
}

Playfield::~Playfield() {

}

// Playfield::Playfield(const Playfield &source) {
//     playfield_outbox_ = source.playfield_outbox_;
//     playfield_inbox_ = source.playfield_inbox_;
// }

void Playfield::generatePlayfield(SDL_Point pOrigin) {
    int playfield_width = cell_size_ * (playfield_width_);
    int playfield_height = cell_size_* (playfield_height_);
    int out_offset = 3;
    int in_offset = 1; 

    playfield_outbox_ = {
        {pOrigin.x - out_offset, pOrigin.y - out_offset},
        {pOrigin.x - out_offset, pOrigin.y + playfield_height + out_offset},
        {pOrigin.x + playfield_width + out_offset, pOrigin.y + playfield_height + out_offset},
        {pOrigin.x + playfield_width + out_offset, pOrigin.y - out_offset},
        {pOrigin.x - out_offset, pOrigin.y - out_offset}
    };

    playfield_inbox_ = {
        {pOrigin.x - in_offset, pOrigin.y - in_offset},
        {pOrigin.x - in_offset, pOrigin.y + playfield_height + in_offset},
        {pOrigin.x + playfield_width + in_offset, pOrigin.y +playfield_height + in_offset},
        {pOrigin.x + playfield_width + in_offset, pOrigin.y - in_offset},
        {pOrigin.x - in_offset, pOrigin.y - in_offset}
    };

    generatePlayfieldCells(pOrigin);
}

void Playfield::generatePlayfieldCells(SDL_Point pOrigin) {
    int num_of_cells = playfield_width_ * playfield_height_;
    for(int i = 0; i < num_of_cells ; i++) {
        cells_.emplace_back(PlayfieldCell(cell_size_, i));
        cells_[i].setCellPosition({pOrigin.x + cell_size_*(i % playfield_width_), pOrigin.y + cell_size_*(i / playfield_width_ )});
    }
}

void Playfield::getPlayfieldBox(SDL_Point *outBox, SDL_Point *inBox) { 
    int num_points = 5;

    for(int i = 0; i < num_points; i++) {
        outBox[i] = playfield_outbox_[i];
        inBox[i] = playfield_inbox_[i];
    }
}


void Playfield::getPlayfieldCells(SDL_Rect *cells, SDL_Color *color) {
    int num_of_cells = playfield_width_ * playfield_height_;
    for(int i = 0; i < num_of_cells ; i++) {
        cells[i] = cells_[i].getCellBox();
        color[i] = cells_[i].getCellColor();
    }
    
}
TETRIS_STATUS Playfield::evaluateActivePiece(Piece *piece) {
    int id = 0;
    int sprite_length;
    if(piece->getSprite().size() > 9) sprite_length = 4; else sprite_length = 3;
    int y = piece->getYPosition();
    int x = piece->getXPosition();
    for(int i = 0; i < piece->getSprite().size() ; i++) {
        if(piece->getSprite()[i] == 1) {
            piece->cell_id_[id] = x + i % sprite_length + (playfield_width_*(i / sprite_length)) + playfield_width_*y;
            if(checkCellCollision(piece->cell_id_[id])) 
                return PIECE_BLOCKED;
            id++;
        }
    }
    return PIECE_FIT;
}

void Playfield::colorPiece(Piece *piece) {
    int id = 0;
    int sprite_length;
    if(piece->getSprite().size() > 9) sprite_length = 4; else sprite_length = 3;
    int y = piece->getYPosition();
    int x = piece->getXPosition();
    for(int i = 0; i < piece->getSprite().size() ; i++) {
        if(piece->getSprite()[i] == 1) {
            piece->cell_id_[id] = x + i % sprite_length + (playfield_width_*(i / sprite_length)) + playfield_width_*y;
            cells_[piece->cell_id_[id]].setCellColor(piece->getColor());
            id++;
        }
    }
}

void Playfield::clearActivePiece(Piece *piece) {
    SDL_Color color = { 0x50, 0x50, 0x50, 0xFF };

    for(int id : piece->cell_id_) {
        if(!cells_[id].getCellStatus())
            cells_[id].setCellColor(color);
    }
}

void Playfield::placeActivePiece(Piece *piece) {
    for(int id : piece->cell_id_) {
        cells_[id].setCellStatus(true);
    }
}

void Playfield::clearLine(int line) {
    std::vector<PlayfieldCell>::iterator cell;
    auto line_begin = cells_.begin() + playfield_width_*line;
    auto line_end = line_begin + playfield_width_;
    for(cell = line_begin; cell < line_end; cell++) {
        cell->Clear();
    }
}

int Playfield::Update(Piece *piece) {
    int line_check;
    bool line_complete;
    std::vector<int> completed_lines = {};
    std::vector<int> lines_affected = {};
    bool repeat = false;

    // Get lines affected by piece placement
    for(int id : piece->cell_id_) {
        for(int i : lines_affected) {
            if( i == id / playfield_width_ ) repeat = true;
        }
        if(!repeat) {
            lines_affected.emplace_back(id / playfield_width_);
        }
        else repeat = false;
    }
    #ifdef VERBOSE
    std::cout << "lines affected: " << lines_affected.size() << std::endl; //debug stuff
    #endif
    
    // Check line completion
    for(int line : lines_affected) {
        for(int i = 0; i < playfield_width_; i++) {
            line_complete = cells_[i + (playfield_width_*line)].getCellStatus();
            if(!line_complete) break;
        }
        if(line_complete) {
            //Clear completed lines
            clearLine(line);
            completed_lines.emplace_back(line);
        }
            
    }
    #ifdef VERBOSE
    for(int line : completed_lines) std::cout << "clear line: " << line << std::endl;
    #endif

    // Shift remaining lines down
    if(!completed_lines.empty()) {
        std::sort(completed_lines.begin(), completed_lines.end());
        int shift_count = 0;
        int clear_count = 0;
        for(int w = 0 ; w < playfield_width_ ; w++) {
            for(int h = completed_lines.back(); h > 0; h--) {
                if(h > completed_lines.size()){
                cells_[w + (h * playfield_width_)] << cells_[(w + (h * playfield_width_) - (playfield_width_ * completed_lines.size()))];
                shift_count++;
                } else {
                    cells_[w + (h * playfield_width_)].Clear();
                    clear_count++;
                }
            } 
        }
        #ifdef VERBOSE
        std::cout << "shifted cells: " << shift_count << std::endl;
        std::cout << "cleared cells: " << clear_count << std::endl;
        #endif
    }

    return completed_lines.size();

}

Sidefield::Sidefield(SDL_Point pOrigin) {
    playfield_width_ = sidefield_width_;
    playfield_height_ = sidefield_height_;
    cell_size_ = sidecell_size_;

    generatePlayfield(pOrigin);
}

void Sidefield::colorPiece(Piece *piece) {
    int id = 0;
    int y = 0;
    int x = 0;
    int sprite_length;

    switch(piece->getType()) {
    case TETRIS_PIECE::I:
        sprite_length = 4;
        break;
    case TETRIS_PIECE::O:
        sprite_length = 4;
        y++;
        break;
    default:
        sprite_length = 3;
        y++;
        break;
    }
    
    for(int i = 0; i < piece->getSprite().size() ; i++) {
        if(piece->getSprite()[i] == 1) {
            piece->cell_id_[id] = x + i % sprite_length + (playfield_width_*(i / sprite_length)) + playfield_width_*y;
            cells_[piece->cell_id_[id]].setCellColor(piece->getColor());
            id++;
        }
    }
}

void Sidefield::clearField() {
    for (int i = 0; i < 16; i++)
        cells_[i].setCellColor({0x50, 0x50, 0x50, 0xFF});
}


Tetris::Tetris() : engine(dev()),
      rdm_orientation(0, static_cast<int>(3)),
      rdm_piece(TETRIS_PIECE::I, TETRIS_PIECE::Z) {


    SDL_Point pOrigin = {30, 30};
    playfield_ = std::make_shared<Playfield>(pOrigin);

    pOrigin = {350, 30};
    next_field_ = std::make_shared<Sidefield>(pOrigin);

    pOrigin = {350, 200};
    saved_field_ = std::make_shared<Sidefield>(pOrigin);

    pieceSpawner_[TETRIS_PIECE::I] = new SpawnerFor<I_Piece>();
    pieceSpawner_[TETRIS_PIECE::J] = new SpawnerFor<J_Piece>();
    pieceSpawner_[TETRIS_PIECE::L] = new SpawnerFor<L_Piece>();
    pieceSpawner_[TETRIS_PIECE::O] = new SpawnerFor<O_Piece>();
    pieceSpawner_[TETRIS_PIECE::S] = new SpawnerFor<S_Piece>();
    pieceSpawner_[TETRIS_PIECE::T] = new SpawnerFor<T_Piece>();
    pieceSpawner_[TETRIS_PIECE::Z] = new SpawnerFor<Z_Piece>();

}

Tetris::~Tetris() {
}

void Tetris::spawnPiece() {
    if(activePiece_ == nullptr) {
        nextType_ = rdm_piece(engine);
    } else delete activePiece_;
    activePiece_ = pieceSpawner_[nextType_]->spawnPiece(playfield_->getPlayfieldWidth());
    activePiece_->setSpeed(1 + linesCleared / 10 );
    playfield_->colorPiece(activePiece_);
    nextType_ = rdm_piece(engine);
    
    Piece *next = pieceSpawner_[nextType_]->spawnPiece(next_field_->getPlayfieldWidth());
    next_field_->clearField();
    next_field_->colorPiece(next);
    delete next;

}

void Tetris::spawnPiece(int type) {
    delete activePiece_;
    activePiece_ = pieceSpawner_[type]->spawnPiece(playfield_->getPlayfieldWidth());
    activePiece_->setSpeed(1 + linesCleared / 10 );
    playfield_->colorPiece(activePiece_);

}


void Tetris::savePiece() {
    playfield_->clearActivePiece(activePiece_);
    if( !savedPiece_ ) {
        savedPiece_ = true;
        saveType_ = activePiece_->getType();
        saved_field_->clearField();
        saved_field_->colorPiece(activePiece_);
        spawnPiece();
    } 
    else {
        int holdType = saveType_;
        saveType_ = activePiece_->getType();
        saved_field_->clearField();
        saved_field_->colorPiece(activePiece_);

        spawnPiece(holdType);
    }
}

void Tetris::Update(bool &running) {
    playfield_->clearActivePiece(activePiece_);

    switch( activePiece_->Update(playfield_.get()) )
    {
    case TETRIS_STATUS::PIECE_ACTIVE:
        playfield_->colorPiece(activePiece_);
        break;
    case TETRIS_STATUS::PIECE_PLACED:
        //Check if any line has been completed
        linesCleared += playfield_->Update(activePiece_);
        spawnPiece();
        running = !activePiece_->evaluatePlace(playfield_.get());
        break;
    default:
        break;

    }

}