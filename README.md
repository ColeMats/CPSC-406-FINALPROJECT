# Chess AI

## Students Information
- Alan Lu, Cole Matsueda, Christopher Isidro
- 2378209, 2343554, 2370110
- allu@chapman.edu, cmatsueda@chapman.edu, cisidro@chapman.edu
- CPSC406-02

## Source Files
- Tree.cpp
- Tree.h
- main.cpp

## Known Issues/Deviations
- N/A

## References
- N/A

## Instructions
- to run chess game:
    - switch to source folder
    - g++ *.cpp 
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

## FUTURE PLANS 
- NEED to make a new feature where player and AI are identified and make use of getCurrentTurn to see which method should be called (movePiece || engineMovePiece)

## FOR ALAN <3
- 

# FOR TALLY <3
- in main.cpp line #1053 is where AI move should go (right after player moves)