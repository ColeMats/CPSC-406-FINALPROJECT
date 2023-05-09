
#ifndef SEARCH_H
#define SEARCH_H

#include "MoveGen.h"
#include <iostream>

class Search{
    public:
        Search(){};
        Search(Board &board);
        ~Search(){};

        Move getBestMove();
        int getBestScore();
        
        // evaluates status of the board (who is winning) based on if number is pos or negative
        int evaluate(Board &board);

        // gets score of board for certain color based on values of pieces
        // p=1, b=3, n=3, r=5, q=9
        int countMaterialsOnBoard(Board &board, Color color);

        // void rootMax(Board &board, int depth);


    private:
        static const int DEFAULT_DEPTH = 7;
        static const int MAX_DEPTH = 10;
        static const int MIN_DEPTH = 3;

        Move m_bestMove;
        int m_bestScore;

        // starts search algorithm
        // finds bestMove out of all possible moves
        void rootMax(Board &board, int depth);

        // maxiplayer = true false --> BLACK == true, WHITE == false (based on next player's move)
        void miniMax(Board &board, int depth, bool maxiPlayer, int alpha, int beta);

};



#endif 