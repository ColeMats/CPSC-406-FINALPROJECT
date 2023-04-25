#ifndef DEFS_H
#define DEFS_H

#include <cstdlib>
#include <iostream>

enum Color{
    WHITE,
    BLACK
};

enum PieceType{
    PAWN,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING
};

struct Position {
    int iRow;
    int iCol;
};

#endif