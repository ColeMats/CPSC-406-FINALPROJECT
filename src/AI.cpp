
#include "AI.h"

// basically have this file run through all the choices, pick the best move, and return the string "move-move" format via getBestMove();

AI::AI(char board[8][8]){
    Board currBoard(board, BLACK);
    m_search = Search(currBoard); // Initialize the Search object with currBoard
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

    // int userInput;
    // std::cout << "1 for ai move, 2 for basic" << std::endl;
    // std::cin >> userInput;
    // if (userInput == 1) {
    //     getAIMoveMinimax(board);
    // } else if (userInput == 2) {
    //     getAIMoveBasic(board);
    // }

    getAIMoveMinimax(board);
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
    m_search.rootMax(board, 5);
    // if(board.getActivePlayer() == WHITE){
    //     m_search.rootMax(board, 5);
    // }
    // else{
    //     m_search.rootMin(board, 5);
    // }
    m_AIMove = m_search.getBestMove().toNotation();

    // m_AIMove += moveGen.toNotation(m_search.getBestMove().getFrom());
    // m_AIMove += "-";
    // m_AIMove += moveGen.toNotation(m_search.getBestMove().getTo());
}