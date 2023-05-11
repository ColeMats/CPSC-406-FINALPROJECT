
#include "Search.h"

Search::Search(Board &board){
    Move m_bestMove = Move();
    m_tree.setRoot(new TreeNode());
}

Move Search::getBestMove(){
    return m_bestMove;
}

int Search::getBestScore(){
    return m_bestScore;
}

void Search::rootMax(Board &board, int depth){
    int alpha = -INF;
    int beta = INF;

    m_bestScore = minimax(board, depth, alpha, beta, board.getActivePlayer());
}

void Search::rootMin(Board &board, int depth){
    int alpha = INF;
    int beta = -INF;

    m_bestScore = minimax(board, depth, alpha, beta, board.getActivePlayer());
}

int Search::minimax(Board &board, int depth, int alpha, int beta, Color color){
    MoveGen moves(board);
    MoveList legalMoves = moves.getLegalMoves();
    
    if (depth == 0 || legalMoves.size() == 0) {
        return evaluate(board);
    }

    int bestScore = color == BLACK ? -INF : INF;

    for (int i = 0; i < legalMoves.size(); ++i) {
        Move move = legalMoves[i];
        Board movedBoard = board;
        movedBoard.doMove(move);
        movedBoard.setActivePlayer(movedBoard.getOppositeColor(movedBoard.getActivePlayer()));
        TreeNode* childNode = new TreeNode();
        m_tree.addChild(board.getTreeNode(), move.toNotation(), childNode);
        movedBoard.setTreeNode(childNode);

        int score = minimax(movedBoard, depth - 1, alpha, beta, movedBoard.getActivePlayer());

        if (color == BLACK) {
            if (score > bestScore) {
                bestScore = score;
                if (depth == 5) {
                    m_bestMove = move;
                }
            }
            alpha = fmax(alpha, score);
        } else {
            if (score < bestScore) {
                bestScore = score;
            }
            beta = fmin(beta, score);
        }

        if (beta <= alpha) {
            break; // Alpha-beta pruning
        }
    }

    return bestScore;
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