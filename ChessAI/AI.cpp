
#include "AI.h"

// basically have this file run through all the choices, pick the best move, and return the string "move-move" format via getBestMove();

AI::AI(char board[8][8]){
    Board currBoard(board, BLACK);
    m_AIMove = "";
    start(currBoard);
}

std::string AI::getAIMove(){
    return m_AIMove;
}

void AI::start(Board &board){
    // Search search(board);
    // search.rootMax(board, DEFAULT_DEPTH);
    // m_AIMove = search.getBestMove();
    getAIMoveMinimax(board);
    //getAIMoveBasic(board);
}

void AI::getAIMoveBasic(Board &board){
    MoveGen moveGen(board, BLACK);
    MoveList moves = moveGen.getLegalMoves();
    if(moves.size() == 0){
        // do something?
        return;
    }
    int maxMove = 0;
    Move bestMove = Move();
    for(auto move : moves){
        if(move.getMoveValue() > maxMove){
            maxMove = move.getMoveValue();
            bestMove = move;
        }
    }
    if(maxMove == 0){
        bestMove = moves[0];
    }
    m_AIMove += moveGen.toNotation(bestMove.getFrom());
    m_AIMove += "-";
    m_AIMove += moveGen.toNotation(bestMove.getTo());
}

void AI::getAIMoveMinimax(Board &board){
    if(board.getActivePlayer() == WHITE){
        m_search.rootMax(board, 4);
    }
    else{
        m_search.rootMin(board, 4);
    }
    m_AIMove = m_search.getBestMove().toNotation();
}