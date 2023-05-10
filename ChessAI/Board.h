
#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "Tree.h"
#include "defs.h"
#include "Move.h"

/*
* @brief Board class to store pieces, get attacks (from opponent), and other board manipulations
* analyzes positions of all piece types and can generate potential attacks from opponent 
*/

class Board{
    public:
        /*
        * Default constructor
        * initializes with starting board and activePlayer = white
        */
        Board();

        /*
        * Overloaded constructor
        * @param char[8][8]
        * default activePlayer is WHITE
        */
        Board(char board[8][8]);

        /*
        * Overloaded constructor
        * @param char[8][8] of preexisting board
        * @param Color of player color (BLACK or WHITE)
        */
        Board(char board[8][8], Color activeColor);

        ~Board(){};

        // sets active player
        void setActivePlayer(Color player);

        /*
        * gets active player's color
        * @return Color of activePlayer
        */
        Color getActivePlayer();

        // prints current board, for testing
        void printBoard();

        // saves all BLACK and WHITE pieces to corresponding vectors
        void logAllPiecesOnBoard();

        bool isQueenActive(Color color);

        // returns characrter rep of piece at board location (even if empty)
        char getPieceAtLocation(int row, int col);

        // returns color of piece at board location (assumes there is piece there)
        Color getColorAtLoc(int row, int col);

        // returns boolean if square is empty
        bool isEmptySquare(int row, int col);

        // compares two squares to see if same cordinate
        bool isSameSquare(int row, int col, Position target);

        // makes sure row and col within board's bounds (0 <= row/col < 8)
        // good for looking at moves
        bool inBounds(int row, int col);

        // gets victim's color 
        Color getOppositeColor(Color c);

        // generates attacks for pawns, rooks, bishops, knights, and queens
        bool getPawnAttacks(Color color, Position tagetPos);
        bool getRookAttacks(Color color, Position targetPos);
        bool getBishopAttacks(Color color, Position targetPos);
        bool getKnightAttacks(Color color, Position targetPos);
        bool getQueenAttacks(Color color, Position targetPos);

        /*
        * checks if piece at attackPos can reach targetPos, given the directional move
        * @param Position attackPos position of attacking piece (active player)
        * @param Position targetPos position of target piece (inactive player)
        * @param Direction attackDir movement pattern of attacking piece (diagonal, horizontal, etc)
        * @param Color color of attacking piece
        */
        bool squareCanAttack(Position attackPos, Position targetPos, Direction attackDir, Color attackColor);

        /*
        * checks if active player's king is in check
        * uses squareCanAttack to look at opponent's possible attacks on active player's king
        * @param Color of active player
        */
        bool colorIsInCheck(Color color);

        /*
        * creates temp board with the specific move
        * @param Move move the move that is being tried
        */
        void doMove(Move move); 

        // bool isKingSafe();
        // bool isCheck();
    

        // accessors for vector lists of positions of specific piece types
        // param color of active player
        std::vector<Position> getPawnLocations(Color pieceColor); // black = AI, white = player
        std::vector<Position> getRookLocations(Color pieceColor);
        std::vector<Position> getBishopLocations(Color pieceColor);
        std::vector<Position> getKnightLocations(Color pieceColor);
        Position getQueenLocations(Color pieceColor);
        Position getKingLocations(Color pieceColor);

        
        // initial default board setting
        char initial_board[8][8] =
        {
            { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },
            { 'P',  'P',  'P',  'P',  'P',  'P',  'P',  'P' },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 'p',  'p',  'p',  'p',  'p',  'p',  'p',  'p' },
            { 'r',  'n',  'b',  'q',  'k',  'b',  'n',  'r' },
        };

        // variables for piece positions of black and white players
        // without color in name == BLACK == AI
        // "player" == WHITE == human
        std::vector<Position> pawnPos;
        std::vector<Position> rookPos;
        std::vector<Position> bishopPos;
        std::vector<Position> knightPos;
        Position queenPos;
        Position kingPos;  

        std::vector<Position> playerPawnPos;
        std::vector<Position> playerRookPos;
        std::vector<Position> playerBishopPos;
        std::vector<Position> playerKnightPos;
        Position playerQueenPos;
        Position playerKingPos;  

        // knight move offsets to make checking moves easier
        int knighRowOffsets[8] = {2, 2, 1, -1, -2, -2, -1, 1};
        int knightColOffsets[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

        // king move offsets to make checking moves easier
        int kingRowOffsets[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int kingColOffsets[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        // implementing tree functions
        TreeNode* getTreeNode();
        void setTreeNode(TreeNode* treeNode);

    private:
        char m_board[8][8];
        Color activePlayer;
        bool queenActive;
        TreeNode* m_treeNode;
};

#endif