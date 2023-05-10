#ifndef MOVEGEN_H
#define MOVEGEN_H

#include <iostream>
// #include "Tree.h"
// #include "TreeNode.h"
// #include "chess.h"

#include "defs.h"
#include "Move.h"
#include "Board.h"
#include <string.h>
#include <vector>
#include <unordered_map>

typedef std::vector<Move> MoveList;

/*
Things left to do:
- do white moves
- think about adding piece type to move
- fill legal moves list (would moving piece result in check)
*/

class MoveGen{
    public:

        /*
        * default move constructor, initialized starting mored
        */
        MoveGen();
        /*
        * overloaded constructor
        */
        MoveGen(Board &board);
        MoveGen(Board &board, Color activeColor);
        ~MoveGen();
        
        
        /* might be necessary later */
        // static int getPieceColor(char piece); // int piece = piece value
        // static bool isPlayerPiece(char piece);
        // static bool isComputerPiece(char piece);
        
        /*
        * initializes MoveLists and calls genMove functions
        */
        void setBoard(Board &board);

        void printBoard(Board &board);

        /*
        functions for testing correctness of move generation
        */
        void printMoves();

        void printLegalMoves();
        std::string toNotation(Position pos);
        std::string selectMove();

        /*
        * calls functions to generate all possible moves
        * currently considered only computer (black) moves
        * must implement choice between generating white vs black moves (for depth search)
        */ 
        void genMoves(Board &board);

        void genLegalMoves(Board &board);

        MoveList getLegalMoves();

        /*
        * generates all possible pawn moves
        */
        void genBlackPawnMoves(Board &board);

        void genWhitePawnMoves(Board &board);

        /*
        * functions for pawn moves (single, double, and if attack possible)
        */
        void genBlackPawnSingleMoves(Board &board, Position pos);
        void genBlackPawnDoubleMoves(Board &board, Position pos);
        void genBlackPawnLeftAttack(Board &board, Position pos);
        void genBlackPawnRightAttack(Board &board, Position pos);

        void genWhitePawnSingleMoves(Board &board, Position pos);
        void genWhitePawnDoubleMoves(Board &board, Position pos);
        void genWhitePawnLeftAttack(Board &board, Position pos);
        void genWhitePawnRightAttack(Board &board, Position pos);

        void genRookMoves(Board &board);
        void genBishopMoves(Board &board);
        void genKnightMoves(Board &board);
        void genQueenMoves(Board &board);
        void genKingMoves(Board &board);

        /*
        * for knight moves
        */
        void genKnightHops(Board &board, Position pos);

        /*
        * functions for sliding moves (horizontal, vertical, and diagonal) 
        * used by rook, bishop, and/or queen
        */
        void genHorizontalSlideMoves(Board &board, Position pos, PieceType type);
        void genVerticalSlideMoves(Board &board, Position pos, PieceType type);
        void genDiagonalSlidemoves(Board &board, Position pos, PieceType type);
        


    private:
        MoveList m_moves;
        MoveList m_legalMoves;

        int kingRowOffsets[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int kingColOffsets[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        int knighRowOffsets[8] = {2, 2, 1, -1, -2, -2, -1, 1};
        int knightColOffsets[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

        // char m_board[8][8];

        // std::unordered_map<char, int> pieceValues;


        

};

#endif