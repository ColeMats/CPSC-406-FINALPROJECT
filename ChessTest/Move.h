
#ifndef MOVE_H
#define MOVE_H

#include "defs.h"
#include <string.h>
#include <iostream>

/*
* @brief Move class to store info about a particular move
* stores Positions from and to (in the form of ints)
* stores char representation of captured piece if attack move
* includes move value variable to min-max and alpha-beta pruning
*/

class Move{
    public:
        Move();
        // might have to add piece type once that's figured out
        Move(Position from, Position to);
        Move(Position from, Position to, PieceType type);
        ~Move(){};

        Position getFrom();
        Position getTo();
        void setCapturedPieceType(char piece);
        char getCapturedPieceType();
        void setMoveValue(int value);
        int getMoveValue();
        PieceType getPieceType();
        void printPieceType();

    private:
        Position m_from;
        Position m_to;
        char m_capturedType;
        int m_value;
        PieceType m_pieceType;


};

#endif