


Following similar format to the UCI shallow blue (https://github.com/GunshipPenguin/shallow-blue/tree/master/src) in regards to pseudo-legal and legal move generation, saving move into a created Move object, 
(future) depth first (min/max) search of possible moves, etc.

Literally the only things left to do:
- minimax search with alphabeta pruning (I have it partially set up)
- inserting it into the game

Minimax: depth-first search
- algorithm is in Search.cpp file
- recursive to certain depth (decrementing depth until depth = 0) (I have default depth set to 5)
    - if depth = 0, evaluate() (in search class) and recurse back
    - the score is based on (value of black pieces on board) - (value of white pieces on board), * -1 if looking at white moves (want lowest score for white)
- alpha = INF, beta = -INF, replace with the depth first search 
    - pruning = less searching
- for each recursion:
    - get list of legal moves (MoveGen movegen(board); MoveList moves = movegen.getLegalMoves();)
    - if moves.size() == 0, checkmate (return with like +/- INF depending whos in checkmate and whos turn it is)
    - iterate through moves list, make tempt board (Board tempboard = board), do move (tempBoard.doMove(moves[i])), change active player color, call minimax (recurse) with decrementing depth and alternating signs for alpha/beta

Lots of examples


Inserting into game:
- once minimax is done, replace the getAIMoveBasic(board) with getAIMoveMinimax(board) in search function of AI class.
- in main.cpp (of actual game), replace "std::string compMove = current_game->getCompMove();" with "AI ai(current_game->getBoard(), BLACK); std::string compMove = ai.getAIMove();"
    - will have to make a getBoard() function in Game function
- i think that would do the trick


It's literally mostly just the minimax and alpha-beta left cuz the move generation and rule checking took longer than i had anticipated. Theres a lot of literature and 
pseudocode on both. I've tested it and to my knowledge there is not bugs but I don't know if it holds for complex board configurations. I've just been checking if it can identify if moves are valid (does it result in checking its own king,
is there a piece it its way, etc), identifying capture moves, and so on.

I haven't incorporated any enpassant or castling moves (because I don't understand them) but they should be easy enough to integrate if time permits.

If we're feeling ambitious, can do movelist ordering before doing alpha-beta search (reduces search and search time)

ALSO:
- need to delete Game.h and Game.cpp (don't use)
- haven't used the Tree or TreeNode data structures because the depth-first seach doesn't need it
