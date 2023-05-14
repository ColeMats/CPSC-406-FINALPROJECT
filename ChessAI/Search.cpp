#include "Search.h"

Search::Search(Board &board){
    Move m_bestMove = Move();
    // m_tree.setRoot(new TreeNode());
}

Move Search::getBestMove(){
    return m_bestMove;
}

int Search::getBestScore(){
    return m_bestScore;
}

void Search::rootMax(Board &board, int depth){
    cout << "checkpoint 2" << endl;
    int alpha = -INF;
    int beta = INF;
    cout << "checkpoint 3" << endl;
    cout << board.isValid() << endl;
    cout << "checkpoint 4" << endl;
    int eval = minimax(board, depth, alpha, beta, board.getActivePlayer());
    cout << eval << endl;
}

void Search::rootMin(Board &board, int depth){
    cout << "checkpoint 2" << endl;
    int alpha = INF;
    int beta = -INF;
    cout << "checkpoint 3" << endl;
    m_bestScore = minimax(board, depth, alpha, beta, board.getActivePlayer());
}

int Search::minimax(Board &board, int depth, int alpha, int beta, Color color){
    cout << "minmax function" << endl;
    MoveGen moves(board);
    MoveList legalMoves = moves.getLegalMoves();

    cout << depth << endl;    
    if (depth == 0 || (legalMoves.size() == 0)) {
        cout << "finished" << endl;
        return evaluate(board); // Negate the evaluation score
    }

    cout << "if" << endl;
    if (color == WHITE) { // The maximizing player is now WHITE
        int maxEval = -INF;
        for (int i = 0; i < legalMoves.size(); ++i) {
            Move move = legalMoves[i];
            Board movedBoard = board;
            cout << "white" << endl;
            movedBoard.doMove(move);
            movedBoard.setActivePlayer(movedBoard.getOppositeColor(movedBoard.getActivePlayer()));
            int eval = minimax(movedBoard,(depth-1), alpha, beta, movedBoard.getActivePlayer());
            if (eval > maxEval) {
                maxEval = eval;
                if (depth == 2) { // Update best move only for the root node
                    m_bestMove = move;
                }
            }
            alpha = max(alpha, eval);
            if (beta <= alpha) {
                break; // Alpha-beta pruning
            }
        }
        return maxEval;
    } else { // The minimizing player is now BLACK
        int minEval = INF;
        for (int i = 0; i < legalMoves.size(); ++i) {
            Move move = legalMoves[i];
            Board movedBoard = board;
            cout << "black" << endl;
            movedBoard.doMove(move);
            movedBoard.setActivePlayer(movedBoard.getOppositeColor(movedBoard.getActivePlayer()));
            
            int eval = minimax(movedBoard, (depth-1), alpha, beta, movedBoard.getActivePlayer());
            minEval = min(minEval, eval);
            beta = min(beta, eval);
            if (beta <= alpha) {
                break; // Alpha-beta pruning
            }
        }
        return minEval;
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