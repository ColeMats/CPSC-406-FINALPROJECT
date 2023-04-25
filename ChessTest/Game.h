

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "MoveGen.h"

class Game{
    public:
        Game();
        Game(char board[8][8]);
        ~Game(){};
        // const int initial_board[8][8] =
        // {
        //     // This represents the pieces on the board.
        //     // Keep in mind that pieces[0][0] represents A1
        //     // pieces[1][1] represents B2 and so on.
        //     // Letters in CAPITAL are white
        //     { 5,  3, 4, 9, 50, 4, 3, 5 },
        //     { 1, 1, 1, 1, 1, 1, 1, 1},
        //     { 0, 0, 0, 0, 0, 0, 0, 0},
        //     { 0, 0, 0, 0, 0, 0, 0, 0},
        //     { 0, 0, 0, 0, 0, 0, 0, 0},
        //     { 0, 0, 0, 0, 0, 0, 0, 0},
        //     { -1, -1, -1, -1, -1, -1, -1, -1},
        //     { -5, -3, -4, -9, -50, -4, -3, -5 },
        // };
        const char initial_board[8][8] =
        {
            // This represents the pieces on the board.
            // Keep in mind that pieces[0][0] represents A1
            // pieces[1][1] represents B2 and so on.
            // Letters in CAPITAL are white
            { 'R',  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },
            { 'P',  'P',  'P',  'P',  'P',  'P',  'P',  'P' },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 'p',  'p',  'p',  'p',  'p',  'p',  'p',  'p' },
            { 'r',  'n',  'b',  'q',  'k',  'b',  'n',  'r' },
        };

        void setBoard();
        void setBoard(char board[8][8]);

        void getPieceValueAtPosition(int row, int col);
        
        
        
    
    private:
        char m_board[8][8];
        // MoveGen moveGen;

};