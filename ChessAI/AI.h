
#ifndef AI_H
#define AI_H

#include "MoveGen.h"
#include "Search.h"
#include "Board.h"

class AI{
    public:
        AI(){};
        AI(char board[8][8]);
        ~AI(){};

        void start(Board &board);
        void getAIMoveBasic(Board &board);
        void getAIMoveMinimax(Board &board);

        std::string getAIMove();

        std::string m_AIMove;
    
    private:
        static const int DEFAULT_DEPTH = 5;
        static const int MAX_DEPTH = 10;
        static const int MIN_DEPTH = 3;
        Search m_search;
};

#endif