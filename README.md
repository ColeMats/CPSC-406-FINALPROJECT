# Chess AI

## Students Information
- Alan Lu, Cole Matsueda, Christopher Isidro, Talitha Holcombe
- 2378209, 2343554, 2370110, 2344717
- allu@chapman.edu, cmatsueda@chapman.edu, cisidro@chapman.edu, holcombe@chapman.edu
- CPSC406-02

## Source Files
- Tree.cpp
- Tree.h
- main.cpp

## Known Issues/Deviations
- the representation of the board in the terminal is not complete. "?" appear rather than black and white tiles
- Move generation not complete. The computer can move only pawns, rooks, or bishops. Movement of these pieces is limited, and does not consider all valid moves by each piece.
- use of Tree data structure for move generation not yet implemented
- Game not yet tested beyond a few moves

## References
- N/A

## Instructions
- to run chess game:
    - g++ -std=c++11 *.cpp
    - ./a.out

## CHANGELOG
03/30/2023 - Chris & Cole
- uploaded first version of working chess engine 

03/31/2023 - Chris & Cole
- merged chess engine with Alan's tree classes
- added if-statement in main.cpp on line #1050 
    - checks to see if player wants to be black (as opposed to assumed white) 
    - if black, first move goes to AI, then turn is switched to player
    - chess engine should run as normal after
- added/duplicated movePiece as "engineMovePiece"
    - removes conditions for "correctness" of move and board coords
    - reomves inputs (cin) for variables
    - takes new parameters (instead of void) 2 strings representing "from" and "to" respectively (starting and ending positions given by AI)

03/31/2023 to 04/02/2023 - Tally
- removed ability for player to choose playing white or black
    - player automatically assigned white pieces
    - AI automatically assigned black pieces
- began simple move generation functions
- added simple function for AI to choose and play its move
- edited "engineMovePiece"
    - removed parameters (to void)
    - AI move selected by functions in chess.cpp
    - AI's move parsed into Positions "from" and "to"
    
## PROGRESS SINCE WEEK 4
Our goal for the MVP was to have a chess engine that plays moves based on tree generation, either randomly or using alpha-beta pruning. While we have not fully developed tree generation and random/calculated move selection, we were able to create a chess engine that is playable in the console. Our chess engine, at present, has AI move generation, but the move generator is not complete. It also does not consider all valid moves for a given piece. Instead, the first valid move found for each piece being considered is the only move associated with that piece. The move generator and tree generation still needs work in order to make the AI make good moves, not just valid moves.
## FUTURE PLANS 
- NEED to make a new feature where player and AI are identified and make use of getCurrentTurn to see which method should be called (movePiece || engineMovePiece)
- get board to print properly
- re-implement player color choice
- develop move generation through tree data structure
- alpha-beta pruning
