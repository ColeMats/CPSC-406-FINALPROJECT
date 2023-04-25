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
        std::string toNotation(Position pos);

        /*
        * calls functions to generate all possible moves
        * currently considered only computer (black) moves
        * must implement choice between generating white vs black moves (for depth search)
        */ 
        void genMoves(Board &board);

        /*
        * generates all possible pawn moves
        */
        void genPawnMoves(Board &board);

        /*
        * functions for pawn moves (single, double, and if attack possible)
        */
        void genPawnSingleMoves(Board &board, std::vector<Position> pawnPos);
        void genPawnDoubleMoves(Board &board, std::vector<Position> pawnPos);
        void genPawnLeftAttack(Board &board, std::vector<Position> pawnPos);
        void genPawnRightAttack(Board &board, std::vector<Position> pawnPos);

        void genRookMoves(Board &board);
        void genBishopMoves(Board &board);
        void genKnightMoves(Board &board);

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
        // char m_board[8][8];

        // std::unordered_map<char, int> pieceValues;


        

};