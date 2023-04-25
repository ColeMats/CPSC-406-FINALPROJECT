
#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

#include "defs.h"

class Board{
    public:
        Board();
        Board(char board[8][8]);
        ~Board(){};

        // Position* getLocationOfPieces(char p);
        void printBoard();
        void logAllPiecesOnBoard();
        char getPieceAtLocation(int row, int col);
        bool isEmptySquare(int row, int col);


        // void logPieceLocations();
        std::vector<Position> getPawnLocations();
        void printPawnLocations();
        std::vector<Position> getRookLocations();
        std::vector<Position> getBishopLocations();
        std::vector<Position> getKnightLocations();
        Position getQueenLocations();
        Position getKingLocations();




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

        std::vector<Position> pawnPos;
        std::vector<Position> rookPos;
        std::vector<Position> bishopPos;
        std::vector<Position> knightPos;
        Position queenPos;
        Position kingPos;  
    private:
        char m_board[8][8];
              
    

};

#endif