// #include "Game.h"
#include "MoveGen.h"
#include "Board.h"


int main(){

    
    char testBoard[8][8] =
        {
            { 0x20,  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },
            { 0x20,  'P',  'P',  'P',  'P',  'P',  'P',  'P' },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 'b', 0x20, 0x20 },
            { 'r', 'b', 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 'R', 0x20, 0x20, 'r', 0x20, 0x20 },
            { 0x20,  'p',  'p',  'p',  'p',  'p',  'p',  'p' },
            { 0x20,  'n',  0x20,  'q',  'k',  0x20,  'n',  0x20 },
        };
    // Board board(testBoard);
    Board board;
    board.printBoard();
    MoveGen moveGen(board);

    moveGen.printMoves();
    // moveGen.printBoard(board);

    // delete game;

    return 0;
}