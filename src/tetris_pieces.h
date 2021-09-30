#ifndef TETRIS_PIECES_H
#define TETRIS_PIECES_H

//I Piece orientations
const int kImode0[16] =    {0, 0, 0, 0,
                            1, 1, 1, 1,
                            0, 0, 0, 0,
                            0, 0, 0, 0};
const int kImode1[16] =    {0, 0, 1, 0,
                            0, 0, 1, 0,
                            0, 0, 1, 0,
                            0, 0, 1, 0};
const int kImode2[16] =    {0, 0, 0, 0,
                            0, 0, 0, 0,
                            1, 1, 1, 1,
                            0, 0, 0, 0};
const int kImode3[16] =    {0, 1, 0, 0,
                            0, 1, 0, 0,
                            0, 1, 0, 0,
                            0, 1, 0, 0};

//J Piece orientations
const int kJmode0[9] = {1, 0, 0,
                        1, 1, 1,
                        0, 0, 0};
const int kJmode1[9] = {0, 1, 1,
                        0, 1, 0,
                        0, 1, 0};
const int kJmode2[9] = {0, 0, 0,
                        1, 1, 1,
                        0, 0, 1};
const int kJmode3[9] = {0, 1, 0,
                        0, 1, 0,
                        1, 1, 0};

//L Piece orientations
const int kLmode0[9] = {0, 0, 1,
                        1, 1, 1,
                        0, 0, 0};
const int kLmode1[9] = {0, 1, 0,
                        0, 1, 0,
                        0, 1, 1};
const int kLmode2[9] = {0, 0, 0,
                        1, 1, 1,
                        1, 0, 0};
const int kLmode3[9] = {1, 1, 0,
                        0, 1, 0,
                        0, 1, 0};

//O Piece orientations
const int kOmode0[16] =    {0, 1, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0};
const int kOmode1[16] =    {0, 1, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0};
const int kOmode2[16] =    {0, 1, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0};
const int kOmode3[16] =    {0, 1, 1, 0,
                            0, 1, 1, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0};

//S Piece orientations
const int kSmode0[9] = {0, 1, 1,
                        1, 1, 0,
                        0, 0, 0};
const int kSmode1[9] = {0, 1, 0,
                        0, 1, 1,
                        0, 0, 1};
const int kSmode2[9] = {0, 0, 0,
                        0, 1, 1,
                        1, 1, 0};
const int kSmode3[9] = {1, 0, 0,
                        1, 1, 0,
                        0, 1, 0};

//T Piece orientations
const int kTmode0[9] = {0, 1, 0,
                        1, 1, 1,
                        0, 0, 0};
const int kTmode1[9] = {0, 1, 0,
                        0, 1, 1,
                        0, 1, 0};
const int kTmode2[9] = {0, 0, 0,
                        1, 1, 1,
                        0, 1, 0};
const int kTmode3[9] = {0, 1, 0,
                        1, 1, 0,
                        0, 1, 0};

//Z Piece orientations
const int kZmode0[9] = {1, 1, 0,
                        0, 1, 1,
                        0, 0, 0};
const int kZmode1[9] = {0, 0, 1,
                        0, 1, 1,
                        0, 1, 0};
const int kZmode2[9] = {0, 0, 0,
                        1, 1, 0,
                        0, 1, 1};
const int kZmode3[9] = {0, 1, 0,
                        1, 1, 0,
                        1, 0, 0};

#endif