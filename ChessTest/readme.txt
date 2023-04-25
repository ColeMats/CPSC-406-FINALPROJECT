

MoveGen and Move are the two important files for this. Assuming that the 2D array of the chess board from front end (main.cpp) will be passed as a parameter in functions involving AI move generation. 
The end format is likely going to be passing the 2D array into the AI move generation, which will return a string of the computer's move (i.g. "A2-A3") so it can be parsed by pre-defined functions in main.

Following similar format to the UCI shallow blue (https://github.com/GunshipPenguin/shallow-blue/tree/master/src) in regards to pseudo-legal and legal move generation, saving move into a created Move object, 
(future) depth first (min/max) search of possible moves, etc.

Right now, pseudo-legal moves can be generated. Future work includes finding legal moves, considering en passant/castling/check/etc., min max search (with alpha-beta pruning), etc.