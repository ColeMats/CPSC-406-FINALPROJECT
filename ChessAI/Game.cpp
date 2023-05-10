
#include "Game.h"

Game::Game(){
    setBoard();
    
}

Game::Game(char board[8][8]){
    setBoard(board);
    
}

void Game::setBoard(){
    memcpy(m_board, initial_board, sizeof(char)*8*8);
}

void Game::setBoard(char board[8][8]){
    for(int i = 0; i<8;++i){
        for(int j = 0; j<8;++j){
            m_board[i][j] = board[i][j];
        }
    }
}

// void Game::getPieceValueAtPosition(int row, int col){
//     MoveGen moveGen;
//     moveGen.setBoard(m_board);
//     char chPiece = m_board[row][col];
//     moveGen.getPieceValue(chPiece);
// }