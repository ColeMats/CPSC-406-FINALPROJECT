#ifndef DEFS_H
#define DEFS_H

#include <cstdlib>
#include <iostream>
#include <limits>

enum Color{
    WHITE,
    BLACK,
    EMPTY
};

enum PieceType{
    PAWN,
    ROOK,
    BISHOP,
    KNIGHT,
    QUEEN,
    KING
};

enum Direction{
    DIAGONAL,
    HORIZONTAL,
    VERTICAL,
    LSHAPE, // knight movement
    PATTACK //pawn attack direction
};

struct Position {
    int iRow;
    int iCol;
};

const int INF = std::numeric_limits<int>::max();




#endif