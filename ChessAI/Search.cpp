#include "Search.h"

Search::Search(Board &board) : m_bestMove(Move()) {
    // Move m_bestMove = Move();
    // m_tree.setRoot(new TreeNode());
}

Move Search::getBestMove(){
    return m_bestMove;
}

int Search::getBestScore(){
    return m_bestScore;
}

void Search::rootMax(Board &board, int depth){
    m_searchDepth = depth;
    int alpha = -INF;
    int beta = INF;
    int eval = minimax(board, depth, alpha, beta, board.getActivePlayer());
}

void Search::rootMin(Board &board, int depth){
    m_searchDepth = depth;
    int alpha = INF;
    int beta = -INF;
    m_bestScore = minimax(board, depth, alpha, beta, board.getActivePlayer());
}

int Search::minimax(Board &board, int depth, int alpha, int beta, Color color){
    MoveGen moves(board);
    MoveList legalMoves = moves.getLegalMoves();
    if (depth == 0 || (legalMoves.size() == 0)) {
        return evaluate(board);
    }
    
    if (color == WHITE) { 
        int maxEval = -INF;
        Move bestMove;
        for (int i = 0; i < legalMoves.size(); ++i) {
            Move move = legalMoves[i];
            Board movedBoard = board;
            movedBoard.doMove(move);
            movedBoard.setActivePlayer(movedBoard.getOppositeColor(movedBoard.getActivePlayer()));
            int eval = minimax(movedBoard, depth-1, alpha, beta, movedBoard.getActivePlayer());
            if (eval > maxEval) {
                maxEval = eval;
                bestMove = move;
                if (depth == m_searchDepth) {
                    m_bestMove = bestMove;
                }
            }
            alpha = max(alpha, eval);
            if (beta <= alpha) {
                break; 
            }
        }
        return maxEval;
    } else {
        int minEval = INF;
        Move bestMove;
        for (int i = 0; i < legalMoves.size(); ++i) {
            Move move = legalMoves[i];
            Board movedBoard = board;
            movedBoard.doMove(move);
            movedBoard.setActivePlayer(movedBoard.getOppositeColor(movedBoard.getActivePlayer()));
            int eval = minimax(movedBoard, depth-1, alpha, beta, movedBoard.getActivePlayer());
            if (eval < minEval) {
                minEval = eval;
                bestMove = move;
                if (depth == m_searchDepth) {
                    m_bestMove = bestMove;
                }
            }
            beta = min(beta, eval);
            if (beta <= alpha) {
                break;
            }
        return minEval;
        }
    }
}


int Search::evaluate(Board &board){
    int blackScore = countMaterialsOnBoard(board, BLACK);
    int whiteScore = countMaterialsOnBoard(board, WHITE);
    return whiteScore - blackScore; // Higher score is better for WHITE
}

int Search::countMaterialsOnBoard(Board &board, Color color){
    int total = 0;
    total += board.getPawnLocations(color).size() * 1;
    total += board.getRookLocations(color).size() * 5;
    total += board.getBishopLocations(color).size() * 3;
    total += board.getKnightLocations(color).size() * 3;
    if(board.isQueenActive(color)) 
        total += 9;
    return total;
}