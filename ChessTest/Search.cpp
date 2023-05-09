
#include "Search.h"

Search::Search(Board &board){
    Move m_bestMove = Move();
}

Move Search::getBestMove(){
    return m_bestMove;
}

int Search::getBestScore(){
    return m_bestScore;
}

void Search::rootMax(Board &board, int depth){
    MoveGen moves(board);
    MoveList legalMoves = moves.getLegalMoves();
    
    if(legalMoves.size() == 0){
        m_bestMove = Move();
        m_bestScore = -INF;
        return;
    }

    int alpha = INF;
    int beta = -INF;
    int currScore;
    for(int i=0; i<legalMoves.size(); ++i){
        Move move = legalMoves[i];
        Board movedBoard = board;
        board.doMove(move);
        // minimax algorithm. if looking at black, max, if looking at white, min
    }
    
}


int Search::evaluate(Board &board){
    int blackScore = countMaterialsOnBoard(board, BLACK);
    int whiteScore = countMaterialsOnBoard(board, WHITE);
    int evaluation = blackScore - whiteScore;
    if(board.getActivePlayer() == WHITE){
        return evaluation * -1;
    }
    return evaluation;
}

int Search::countMaterialsOnBoard(Board &board, Color color){
    int total = 0;
    total += board.getPawnLocations(color).size() * 1;
    total += board.getRookLocations(color).size() * 5;
    total += board.getBishopLocations(color).size() * 3;
    total += board.getKnightLocations(color).size() * 3;
    if(board.isQueenActive(color)) total += 9;
    return total;
}