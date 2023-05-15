# Chess AI

## Students Information
- Alan Lu, Cole Matsueda, Christopher Isidro, Talitha Holcombe
- 2378209, 2343554, 2370110, 2344717
- allu@chapman.edu, cmatsueda@chapman.edu, cisidro@chapman.edu, holcombe@chapman.edu
- CPSC406-02

## Source Files
- Tree.cpp
- Tree.h
- chess.cpp
- chess.h
- resource.h
- user_interface.cpp
- user_interface.h
- main.cpp

## Known Issues/Deviations
- the representation of the board in the terminal is only compatible with a windows terminal (white and black squares)
    - the white and black squares appear as question marks in a mac terminal.  
    - This was an issue researched by the team but no solution was found.
- 

## References
- Chess Game within console https://github.com/jeromevonk/chess_console
    - Chess game was used as a foundation, found by Cole and Chris.  
    - This game was used to implement basic move rules and game rules 
    - This game is stricly player vs player 
    - Functions were added to make game usable by backend team that implemented AI algorithm to play against a user

- Chess video tutorials to get a grasp of different approaches to programming chess AI 
    - https://www.youtube.com/watch?v=U4ogK0MIzqk&t=393s&ab_channel=SebastianLague
    - https://www.youtube.com/watch?v=_4EuZI8Q8cs&ab_channel=FamTrinli

- Other websites used to get a grasp on how to program chess engines
    - https://www.freecodecamp.org/news/simple-chess-ai-step-by-step-1d55a9266977/

- Literature Review to use as a foundation for min/max algorithms with alpha-beta pruning
    - https://ieeexplore.ieee.org/document/9510148
    - https://www.chessprogramming.org/Main_Page


## Instructions
- to run chess game:
    - g++ -std=c++11 *.cpp
    - ./a.out

## CHANGELOG
03/31/2023 - Alan
-   Implemented classes for Tree and TreeNode with the following features:
    - TreeNode:
        - Contains a hashmap for piece location with a string (piece) input and int output.
        - Contains a hashmap for future moves with a string (future move) input and a pointer to a TreeNode output.
        - Has getter and setter methods for both hashmaps.
        - Provides print methods to display all possible moves and piece locations.
    - Tree:
        - Provides a method to retrieve the root node.
        - Provides a method to print all possible moves by displaying the children nodes and their future move hash inputs.
        - Provides a getSuccessors method.
- Created Test for Tree class
    - is in the Test Directory

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

This current version (as of 04.02.2023) includes the chess engine as pvp instead of player vs AI.  The move generation is a work in progress but has not been implemented into the chess engine.  Right now, the game is set up to be player vs player, with move generations being made in another class.  This is a step in our future plan to properly implement the generated moves into the engine so that the game can be played as player vs AI.  While we did fall short of our MVP, the process gave us a better perspective on how we want to continue the rest of the project.

## FUTURE PLANS 
- It was suggested to us at the beginning of the project that we could use bit boards instead of characters as a data structure which would make this project more space efficient.
- Changing tree to store data from hashmap to bitboard
- Other than the efficiency of the project, we would also like to make it more visually appealing and turn it into its own executable file to use as a game 
    - Like many games, an idea for future development would be to add difficulties of the chess engine 
