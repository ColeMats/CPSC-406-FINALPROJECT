
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
        /*
        Default constructor
        initalizes m_value to 0, captured piece to 0x20, and to/from positions
        */
        Move();
        /*
        Overloaded constructor
        * @param Position from and Position to
        */
        Move(Position from, Position to);
        /*
        Overloaded constructor
        * @param Positions to and from, PieceType
        */
        Move(Position from, Position to, PieceType type);

        ~Move(){};

        /*
        Accessor and Mutator for Position variables m_to and m_from
        */
        Position getFrom();
        Position getTo();

        /*
        Accessor and mutator for captured piece (char)
        * setCapturedPieceType also sets move value of piece
        */
        void setCapturedPieceType(char piece);
        char getCapturedPieceType();

        /*
        Accessor/mutator for move  value
        * pawn = 1, rook = 5, knight = 3, bishop = 3, queen = 9
        */
        void setMoveValue(int value);
        int getMoveValue();

        /*
        Accessor for PieceType of moved piece
        */
        PieceType getPieceType();

        /*
        Printing piece type of moved piece
        * for testing mostly
        */
        void printPieceType();

        std::string toNotation() const;
    private:
        Position m_from;
        Position m_to;
        char m_capturedType;
        int m_value;
        PieceType m_pieceType;


};

#endif