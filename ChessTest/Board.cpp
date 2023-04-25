#include "Board.h"



Board::Board(){
    memcpy(m_board, initial_board, sizeof(char)*8*8);
    logAllPiecesOnBoard();
    
    
}

Board::Board(char board[8][8]){
    memcpy(m_board, board, sizeof(char)*8*8);
    logAllPiecesOnBoard();

}

char Board::getPieceAtLocation(int row, int col){
    return m_board[row][col];
}

bool Board::isEmptySquare(int row, int col){
    if(m_board[row][col] == 0x20){
        return true;
    }
    return false;
}

void Board::printBoard(){
    for(int i = 0; i<8;++i){
        for(int j = 0; j<8;++j){
            std::cout << m_board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::logAllPiecesOnBoard(){
    for(int i = 0; i<8; ++i){
        for(int j = 0; j<8;++j){
            Position p;
            char temp = m_board[i][j];
            if(islower(temp)){
                switch(temp){
                    case 'p':
                        p.iRow = i;
                        p.iCol = j;
                        pawnPos.push_back(p);
                        break;
                    case 'n':
                        p.iRow = i;
                        p.iCol = j;
                        knightPos.push_back(p);
                        break;
                    case 'r':
                        p.iRow = i;
                        p.iCol = j;
                        rookPos.push_back(p);
                        break;
                    case 'b':
                        p.iRow = i;
                        p.iCol = j;
                        bishopPos.push_back(p);
                        break;
                    case 'q':
                        p.iRow = i;
                        p.iCol = j;
                        queenPos = p;
                        break;
                    case 'k':
                        p.iRow = i;
                        p.iCol = j;
                        kingPos = p;
                        break;
                    default:
                        break;
                }
            }

        }
    }
}

std::vector<Position> Board::getPawnLocations(){
    return pawnPos;
}

std::vector<Position> Board::getRookLocations(){
    return rookPos;
}

std::vector<Position> Board::getBishopLocations(){
    return bishopPos;
}

std::vector<Position> Board::getKnightLocations(){
    return knightPos;
}