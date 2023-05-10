
#include "MoveGen.h"

MoveGen::MoveGen(){
    Board board;
    setBoard(board);
}

MoveGen:: MoveGen(Board &board){
    
    // board.printBoard();
    setBoard(board);
}

MoveGen::MoveGen(Board &board, Color activeColor){
    board.setActivePlayer(activeColor);
    setBoard(board);
}

MoveGen::~MoveGen(){


}

// use board specified by parameter
void MoveGen::setBoard(Board &board){
    m_moves = MoveList();
    m_legalMoves = MoveList();
    genMoves(board);
}

void MoveGen::printBoard(Board &board){
    board.printBoard();
}

void MoveGen::printMoves(){
    std::cout << m_moves.size() << std::endl;
    for(int i=0; i<m_moves.size(); ++i){
        Move moves = m_moves[i];
        // std::cout << toNotation(moves.getFrom()) << "-" << toNotation(moves.getTo()) << std::endl;
        moves.printPieceType();
        std::cout << toNotation(moves.getFrom()) << "-" << toNotation(moves.getTo()) << std::endl;

    }
}

void MoveGen::printLegalMoves(){
    std::cout << m_legalMoves.size() << std::endl;
    for(auto legal : m_legalMoves){
        legal.printPieceType();
        std::cout << toNotation(legal.getFrom()) << "-" << toNotation(legal.getTo()) << std::endl;
    }
}

std::string MoveGen::toNotation(Position pos){
    std::string notation = "";
    notation += pos.iCol + 'A';
    notation += pos.iRow + '1';
    return notation;
}

void MoveGen::genBlackPawnSingleMoves(Board &board, Position pos){ // computer moves -- start @ i=6 
    
    if(board.inBounds(pos.iRow-1, pos.iCol) && board.getPieceAtLocation(pos.iRow-1, pos.iCol) == 0x20){
        Position to;
        to.iRow = pos.iRow - 1;
        to.iCol = pos.iCol;
        m_moves.push_back(Move(pos, to, PAWN));
    }
    
}

void MoveGen::genBlackPawnDoubleMoves(Board &board, Position pos){
    
    if(pos.iRow == 6){
        if(board.getPieceAtLocation(pos.iRow-1, pos.iCol) == 0x20 && board.getPieceAtLocation(pos.iRow-2, pos.iCol) == 0x20){
            Position to;
            to.iRow = pos.iRow -2;
            to.iCol = pos.iCol;
            m_moves.push_back(Move(pos, to, PAWN));
        }
    }
}

void MoveGen::genBlackPawnLeftAttack(Board &board, Position pos){
    
    if(board.inBounds(pos.iRow-1, pos.iCol-1) && isupper(board.getPieceAtLocation(pos.iRow-1, pos.iCol-1))){
        Position to;
        to.iRow = pos.iRow - 1;
        to.iCol = pos.iCol -1;
        Move move = Move(pos, to, PAWN);
        move.setCapturedPieceType(board.getPieceAtLocation(to.iRow, to.iCol));
        m_moves.push_back(move);
    }
    
}
void MoveGen::genBlackPawnRightAttack(Board &board, Position pos){
    
    if(board.inBounds(pos.iRow-1, pos.iCol + 1) && isupper(board.getPieceAtLocation(pos.iRow-1, pos.iCol+1))){
        Position to;
        to.iRow = pos.iRow-1;
        to.iCol = pos.iCol+1;
        Move move = Move(pos, to, PAWN);
        move.setCapturedPieceType(board.getPieceAtLocation(to.iRow, to.iCol));
        m_moves.push_back(move);
    }
}

void MoveGen::genWhitePawnSingleMoves(Board &board, Position pos){ // computer moves -- start @ i=6 
    
    if(board.inBounds(pos.iRow+1, pos.iCol) && board.getPieceAtLocation(pos.iRow+1, pos.iCol) == 0x20){
        Position to;
        to.iRow = pos.iRow - 1;
        to.iCol = pos.iCol;
        m_moves.push_back(Move(pos, to, PAWN));
    }
    
}

void MoveGen::genWhitePawnDoubleMoves(Board &board, Position pos){
    
    if(pos.iRow == 1){
        if(board.getPieceAtLocation(pos.iRow+1, pos.iCol) == 0x20 && board.getPieceAtLocation(pos.iRow+2, pos.iCol) == 0x20){
            Position to;
            to.iRow = pos.iRow +2;
            to.iCol = pos.iCol;
            m_moves.push_back(Move(pos, to, PAWN));
        }
    }
}

void MoveGen::genWhitePawnLeftAttack(Board &board, Position pos){
    
    if(board.inBounds(pos.iRow+1, pos.iCol-1) && islower(board.getPieceAtLocation(pos.iRow+1, pos.iCol-1))){
        Position to;
        to.iRow = pos.iRow + 1;
        to.iCol = pos.iCol -1;
        Move move = Move(pos, to, PAWN);
        move.setCapturedPieceType(board.getPieceAtLocation(to.iRow, to.iCol));
        m_moves.push_back(move);
    }
    
}
void MoveGen::genWhitePawnRightAttack(Board &board, Position pos){
    
    if(board.inBounds(pos.iRow+1, pos.iCol + 1) && islower(board.getPieceAtLocation(pos.iRow+1, pos.iCol+1))){
        Position to;
        to.iRow = pos.iRow+1;
        to.iCol = pos.iCol+1;
        Move move = Move(pos, to, PAWN);
        move.setCapturedPieceType(board.getPieceAtLocation(to.iRow, to.iCol));
        m_moves.push_back(move);
    }
}




void MoveGen::genMoves(Board &board){
    // board.logAllPiecesOnBoard();
    if(board.getActivePlayer() == BLACK){
        genBlackPawnMoves(board);
        
    }
    else if(board.getActivePlayer() == WHITE){
        genWhitePawnMoves(board);
    }
    genRookMoves(board);
    genBishopMoves(board);
    genKnightMoves(board);
    genKingMoves(board);
    genLegalMoves(board);
}

void MoveGen::genLegalMoves(Board &board){
    m_legalMoves.reserve(m_moves.size());
    for(auto move: m_moves){
        Board tempBoard = board;
        tempBoard.doMove(move);
        // tempBoard.printBoard();
        if(!tempBoard.colorIsInCheck(tempBoard.getActivePlayer())&& move.getCapturedPieceType() != 'k' && move.getCapturedPieceType() != 'K'){
            m_legalMoves.push_back(move);
        }
    }
    
}

MoveList MoveGen::getLegalMoves(){
    return m_legalMoves;
}

void MoveGen::genBlackPawnMoves(Board &board){
    std::vector<Position> pawnLoc = board.getPawnLocations(BLACK);
    for(int i=0; i<pawnLoc.size(); ++i){
        genBlackPawnSingleMoves(board, pawnLoc[i]);
        genBlackPawnDoubleMoves(board, pawnLoc[i]);
        genBlackPawnLeftAttack(board, pawnLoc[i]);
        genBlackPawnRightAttack(board, pawnLoc[i]);
    }
    

}

void MoveGen::genWhitePawnMoves(Board &board){
    std::vector<Position> pawnLoc = board.getPawnLocations(WHITE);
    for(int i=0; i<pawnLoc.size(); ++i){
        genWhitePawnSingleMoves(board, pawnLoc[i]);
        genWhitePawnDoubleMoves(board, pawnLoc[i]);
        genWhitePawnLeftAttack(board, pawnLoc[i]);
        genWhitePawnRightAttack(board, pawnLoc[i]);
    }

}

void MoveGen::genQueenMoves(Board &board){
    Position queenPos = board.getQueenLocations(board.getActivePlayer());
    genVerticalSlideMoves(board, queenPos, QUEEN);
    genHorizontalSlideMoves(board, queenPos, QUEEN);
    genDiagonalSlidemoves(board, queenPos, QUEEN);
}

void MoveGen::genRookMoves(Board &board){
    std::vector<Position> rookPos = board.getRookLocations(board.getActivePlayer());
    // std::cout << rookPos.size() << std::endl;
    for(int i=0;i<rookPos.size();++i){
        genVerticalSlideMoves(board, rookPos[i], ROOK);
        genHorizontalSlideMoves(board, rookPos[i], ROOK);
    }
}

void MoveGen::genBishopMoves(Board &board){
    std::vector<Position> bishopPos = board.getBishopLocations(board.getActivePlayer());
    // std::cout << bishopPos.size() << std::endl;
    for(int i=0;i<bishopPos.size();++i){
        genDiagonalSlidemoves(board, bishopPos[i], BISHOP);
    }
}

void MoveGen::genKnightMoves(Board &board){
    std::vector<Position> knightPos = board.getKnightLocations(board.getActivePlayer());
    for(int i=0;i<knightPos.size();++i){
        genKnightHops(board, knightPos[i]);
    }
}

void MoveGen::genKingMoves(Board &board){
    Position kingPos = board.getKingLocations(board.getActivePlayer());
    Position to;
    Color victimColor = board.getOppositeColor(board.getActivePlayer());
    for(int i=0; i<8;++i){
        to.iRow = kingPos.iRow + kingRowOffsets[i];
        to.iCol = kingPos.iCol + kingColOffsets[i];
        if(board.inBounds(to.iRow, to.iCol)){
            if(board.getColorAtLoc(to.iRow, to.iCol) == victimColor){
                Move move = Move(kingPos, to, KING);
                move.setCapturedPieceType(board.getPieceAtLocation(to.iRow, to.iCol));
                m_moves.push_back(move);
            }
            else if(board.isEmptySquare(to.iRow, to.iCol)){
                Move move = Move(kingPos, to, KING);
                m_moves.push_back(move);
            }
        }
    }
}


//super long ugh
void MoveGen::genKnightHops(Board &board, Position pos){
    int row = pos.iRow;
    int col = pos.iCol;
    
    for(int i=0; i<8; ++i){
        if(board.inBounds(row + knighRowOffsets[i], col + knightColOffsets[i])){
            Position to;
            to.iRow = row + knighRowOffsets[i];
            to.iCol = col + knightColOffsets[i];
            if(board.isEmptySquare(to.iRow, to.iCol)){
                Move move = Move(pos, to, KNIGHT);
                m_moves.push_back(move);
            }
            else if(board.getActivePlayer() == BLACK && isupper(board.getPieceAtLocation(to.iRow, to.iCol))){
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(to.iRow, to.iCol));
                m_moves.push_back(move);
            }
            else if(board.getActivePlayer() == WHITE && islower(board.getPieceAtLocation(to.iRow, to.iCol))){
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(to.iRow, to.iCol));
                m_moves.push_back(move);
            }
        }
        
    }

}

void MoveGen::genVerticalSlideMoves(Board &board, Position pos, PieceType type){
    int row = pos.iRow;
    Position to;
    to.iCol = pos.iCol;
    bool cont = true;
    int i = 1;
    Color victimColor = board.getOppositeColor(board.getActivePlayer());
    while((row-i >= 0) && cont){ // moving forward (to white side)
        if((board.isEmptySquare(row -i, pos.iCol))){
            to.iRow = row - i;
            m_moves.push_back(Move(pos, to, type));
            i++;
        }
        else if(board.getColorAtLoc(row-i, pos.iCol) == victimColor){
            to.iRow = row - i;
            Move move = Move(pos, to, type);
            move.setCapturedPieceType(board.getPieceAtLocation(row-i, pos.iCol));
            m_moves.push_back(move);
            cont = false;
        }
        else{
            cont = false;
        }
    }
    cont = true;
    i = 1;
    while((row+i <= 7) && cont){ // moving backward (to own side)
        if((board.isEmptySquare(row +i, pos.iCol))){
            to.iRow = row + i;
            m_moves.push_back(Move(pos, to, type));
            i++;
        }
        else if(board.getColorAtLoc(row+i, pos.iCol) == victimColor){
            to.iRow = row + i;
            Move move = Move(pos, to, type);
            move.setCapturedPieceType(board.getPieceAtLocation(row+i, pos.iCol));
            m_moves.push_back(move);
            cont = false;
        }
        else{
            cont = false;
        }
    }
}
void MoveGen::genHorizontalSlideMoves(Board &board, Position pos, PieceType type){
    int col = pos.iCol;
    Position to;
    to.iRow = pos.iRow;
    bool cont = true;
    int i = 1;
    Color victimColor = board.getOppositeColor(board.getActivePlayer());
    while((col-i >= 0) && cont){ // moving forward (to white side)
        if((board.isEmptySquare(pos.iRow, col-i))){
            to.iCol = col - i;
            m_moves.push_back(Move(pos, to, type));
            i++;
        }
        else if(board.getColorAtLoc(pos.iRow, col-i) == victimColor){
            to.iCol = col - i;
            Move move = Move(pos, to, type);
            move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow, col-i));
            m_moves.push_back(move);
            cont = false;
        }
        else{
            cont = false;
        }
    }
    cont = true;
    i = 1;
    while((col+i <= 7) && cont){ // moving backward (to own side)
        if((board.isEmptySquare(pos.iRow, col+i))){
            to.iCol = col + i;
            m_moves.push_back(Move(pos, to, type));
            i++;
        }
        else if(board.getColorAtLoc(pos.iRow, col+i) == victimColor){
            to.iCol = col + i;
            Move move = Move(pos, to, type);
            move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow, col+i));
            m_moves.push_back(move);
            cont = false;
        }
        else{
            cont = false;
        }
    }
}

void MoveGen::genDiagonalSlidemoves(Board &board, Position pos, PieceType type){
    int row = pos.iRow;
    int col = pos.iCol;
    int rowOffset = 1;
    int colOffset = 1;
    bool cont = true;
    bool leftback, leftfront, rightback, rightforward = true;
    Color victimColor = board.getOppositeColor(board.getActivePlayer());
    while(cont){
        Position to;
        if((row+rowOffset) <= 7){
            if((col + colOffset <= 7) && rightback){
                if(board.getColorAtLoc(row+rowOffset, col+colOffset) == victimColor){
                    to.iRow = row+rowOffset;
                    to.iCol = col+colOffset;
                    Move move = Move(pos, to, type);
                    move.setCapturedPieceType(board.getPieceAtLocation(row+rowOffset, col+colOffset));
                    m_moves.push_back(move);
                    rightback = false;
                }
                else if(board.isEmptySquare(row+rowOffset, col+colOffset)){
                    to.iRow = row+rowOffset;
                    to.iCol = col+colOffset;
                    m_moves.push_back(Move(pos, to, type));
                }
                else{
                    rightback = false;
                }
            }
            else{
                rightback = false;
            }
            if((col-colOffset >= 0) && leftback){
                if(board.getColorAtLoc(row+rowOffset, col-colOffset) == victimColor){
                    to.iRow = row+rowOffset;
                    to.iCol = col+-colOffset;
                    Move move = Move(pos, to, type);
                    move.setCapturedPieceType(board.getPieceAtLocation(row+rowOffset, col-colOffset));
                    m_moves.push_back(move);
                    rightback = false;
                }
                else if(board.isEmptySquare(row+rowOffset, col-colOffset)){
                    to.iRow = row+rowOffset;
                    to.iCol = col-colOffset;
                    m_moves.push_back(Move(pos, to, type));
                }
                else{
                    leftback = false;
                }
            }
            else{
                leftback = false;
            }
        }
        if((row-rowOffset >= 0)){
            if((col + colOffset <= 7) && rightforward){
                if(board.getColorAtLoc(row-rowOffset, col+colOffset) == victimColor){
                    to.iRow = row-rowOffset;
                    to.iCol = col+colOffset;
                    Move move = Move(pos, to, type);
                    move.setCapturedPieceType(board.getPieceAtLocation(row-rowOffset, col+colOffset));
                    m_moves.push_back(move);
                    rightforward = false;
                }
                else if(board.isEmptySquare(row-rowOffset, col+colOffset)){
                    to.iRow = row-rowOffset;
                    to.iCol = col+colOffset;
                    m_moves.push_back(Move(pos, to, type));
                }
                else{
                    rightforward = false;
                }
            }
            else{
                rightforward = false;
            }
            if((col-colOffset >= 0) && leftfront){
                if(board.getColorAtLoc(row-rowOffset, col-colOffset) == victimColor){
                    to.iRow = row-rowOffset;
                    to.iCol = col+-colOffset;
                    Move move = Move(pos, to, type);
                    move.setCapturedPieceType(board.getPieceAtLocation(row-rowOffset, col-colOffset));
                    m_moves.push_back(move);
                    leftfront = false;
                }
                else if(board.isEmptySquare(row-rowOffset, col-colOffset)){
                    to.iRow = row-rowOffset;
                    to.iCol = col-colOffset;
                    m_moves.push_back(Move(pos, to, type));
                }
                else{
                    leftfront = false;
                }
            }
            else{
                leftfront = false;
            }
        }
        if(!rightback && !rightforward && !leftback && !leftfront){
            cont = false;
        }
        rowOffset++;
        colOffset++;
    }
}
