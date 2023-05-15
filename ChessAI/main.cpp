// #include "Game.h"
#include "MoveGen.h"
#include "Board.h"
#include "AI.h"


int main(){
    // char testBoard[8][8] =
    //     {
    //         { 0x20,  'N',  'B',  'Q',  'K',  'B',  'N',  'R' },
    //         { 0x20,  'P',  'P',  'P',  'P',  'P',  'P',  'P' },
    //         { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    //         { 0x20, 0x20, 0x20, 0x20, 0x20, 'b', 0x20, 0x20 },
    //         { 'r', 'b', 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
    //         { 0x20, 0x20, 'R', 0x20, 0x20, 'r', 0x20, 0x20 },
    //         { 0x20,  'p',  'p',  'p',  'p',  'p',  'p',  'p' },
    //         { 0x20,  'n',  0x20,  'q',  'k',  0x20,  'n',  0x20 },
    //     };

    char testBoard[8][8] =
        {
            { 'R',  'N',  'B',  'Q',   'K',  'B',  'N',  'R' },
            { 'P',  'P',  'P',  0x20,  'P',  'P',  0x20,  'P' },
            { 0x20, 0x20, 0x20, 0x20,  0x20, 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 0x20, 'P', 0x20, 0x20, 'P', 0x20 },
            { 0x20, 0x20, 0x20, 0x20, 'p', 0x20, 0x20, 0x20 },
            { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },
            { 'p',  'p',  'p',  'p',   0x20,  'p',  'p',  'p' },
            { 'r',  'n',  'b',  'q',   'k',  'b',  'n',  'r' },
        };

    AI ai(testBoard);
    cout << "the best move in this situation is: " << ai.getAIMove() << std::endl;

    // Board board(testBoard, BLACK);
    // MoveGen moveGen(board);
    // moveGen.printLegalMoves();
    

    /*

    Board board(testBoard, BLACK);
    // Board board;
    board.printBoard();
    if(board.colorIsInCheck(board.getActivePlayer())){
        std::cout << "Black in check\n" << std::endl;
    }
    MoveGen moveGen(board);
    moveGen.printLegalMoves();

    moveGen.printMoves();

    */

    // moveGen.printBoard(board);

    // delete game;

    return 0;
}