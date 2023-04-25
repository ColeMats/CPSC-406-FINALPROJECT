
#include "MoveGen.h"

MoveGen::MoveGen(){
    Board board;
    setBoard(board);
}

MoveGen:: MoveGen(Board &board){
    
    // board.printBoard();
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

std::string MoveGen::toNotation(Position pos){
    std::string notation = "";
    notation += pos.iCol + 'A';
    notation += pos.iRow + '1';
    return notation;
}

void MoveGen::genPawnSingleMoves(Board &board, std::vector<Position> pawnPos){ // computer moves -- start @ i=6 
    for(int i=0;i<pawnPos.size(); ++i){
        Position from = pawnPos[i];
        Position to;
        if((from.iRow > 0) && (board.isEmptySquare(from.iRow-1, from.iCol))){
            to.iRow = from.iRow -1;
            to.iCol = from.iCol;
            m_moves.push_back(Move(from, to, PAWN));
        }
        else if(from.iRow == 0){
            to.iRow = from.iRow -1;
            to.iCol = from.iCol;
            // generate pawn promotion
            m_moves.push_back(Move(from,to, PAWN)); // temporary -- move added to list in promotion function
        }
    }
    
}

void MoveGen::genPawnDoubleMoves(Board &board, std::vector<Position> pawnPos){
    for(int i=0; i<pawnPos.size(); ++i){
        Position from = pawnPos[i];
        // std::cout << from.iRow << std::endl;
        Position to;
        if(from.iRow == 6){
            to.iRow = from.iRow - 2;
            to.iCol = from.iCol;
            if((board.isEmptySquare(to.iRow, to.iCol)) && (board.isEmptySquare(from.iRow -1, from.iCol-1))){
                m_moves.push_back(Move(from,to,PAWN));
            }
        }
    }
}

void MoveGen::genPawnLeftAttack(Board &board, std::vector<Position> pawnPos){
    for(int i=0;i<pawnPos.size();++i){
        Position from = pawnPos[i];
        if(from.iCol > 0){
            // have to add attack promotions (attack & promotion) and enpassant
            if(isupper(board.getPieceAtLocation(from.iRow-1, from.iCol-1))){
                Position to;
                to.iRow = from.iRow - 1;
                to.iCol = from.iCol - 1;
                Move move = Move(from, to, PAWN);
                move.setCapturedPieceType(board.getPieceAtLocation(to.iRow, to.iCol));
                m_moves.push_back(move);
            }
        }
    }
}
void MoveGen::genPawnRightAttack(Board &board, std::vector<Position> pawnPos){
    for(int i=0;i<pawnPos.size();++i){
        Position from = pawnPos[i];
        if(from.iCol < 7){
            // have to add attack promotions (attack & promotion) and enpassant
            if(isupper(board.getPieceAtLocation(from.iRow-1, from.iCol+1))){
                Position to;
                to.iRow = from.iRow - 1;
                to.iCol = from.iCol + 1;
                Move move = Move(from, to, PAWN);
                move.setCapturedPieceType(board.getPieceAtLocation(to.iRow, to.iCol));
                m_moves.push_back(move);
            }
        }
    }
}

void MoveGen::genMoves(Board &board){
    // board.logAllPiecesOnBoard();

    genPawnMoves(board);
    genRookMoves(board);
    genBishopMoves(board);
    genKnightMoves(board);

}

void MoveGen::genPawnMoves(Board &board){
    std::vector<Position> pawnLoc = board.getPawnLocations();
    genPawnSingleMoves(board, pawnLoc);
    genPawnDoubleMoves(board, pawnLoc);
    genPawnLeftAttack(board, pawnLoc);
    genPawnRightAttack(board, pawnLoc);

}

void MoveGen::genRookMoves(Board &board){
    std::vector<Position> rookPos = board.getRookLocations();
    std::cout << rookPos.size() << std::endl;
    for(int i=0;i<rookPos.size();++i){
        genVerticalSlideMoves(board, rookPos[i], ROOK);
        genHorizontalSlideMoves(board, rookPos[i], ROOK);
    }
}

void MoveGen::genBishopMoves(Board &board){
    std::vector<Position> bishopPos = board.getBishopLocations();
    // std::cout << bishopPos.size() << std::endl;
    for(int i=0;i<bishopPos.size();++i){
        genDiagonalSlidemoves(board, bishopPos[i], BISHOP);
    }
}

void MoveGen::genKnightMoves(Board &board){
    std::vector<Position> knightPos = board.getKnightLocations();
    for(int i=0;i<knightPos.size();++i){
        genKnightHops(board, knightPos[i]);
    }
}


//super long ugh
void MoveGen::genKnightHops(Board &board, Position pos){
    
    if(pos.iRow - 2 >= 0){
        if(pos.iCol - 1 >= 0){
            Position to;
            if(isupper(board.getPieceAtLocation(pos.iRow-2, pos.iCol-1))){
                to.iRow = pos.iRow -2;
                to.iCol = pos.iCol -1;
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow-2, pos.iCol-1));
                m_moves.push_back(move);
            }
            else if(board.isEmptySquare(pos.iRow-2, pos.iCol -1)){
                to.iRow = pos.iRow -2;
                to.iCol = pos.iCol -1;
                m_moves.push_back(Move(pos, to, KNIGHT));
            }
        }
        if(pos.iCol + 1 <= 7){
            Position to;
            if(isupper(board.getPieceAtLocation(pos.iRow-2, pos.iCol+1))){
                to.iRow = pos.iRow -2;
                to.iCol = pos.iCol +1;
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow-2, pos.iCol+1));
                m_moves.push_back(move);
            }
            else if(board.isEmptySquare(pos.iRow-2, pos.iCol +1)){
                to.iRow = pos.iRow -2;
                to.iCol = pos.iCol +1;
                m_moves.push_back(Move(pos, to, KNIGHT));
            }
        }
    }
    if(pos.iRow - 1>= 0){
        if(pos.iCol - 2 >= 0){
            Position to;
            if(isupper(board.getPieceAtLocation(pos.iRow-1, pos.iCol-2))){
                to.iRow = pos.iRow -1;
                to.iCol = pos.iCol -2;
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow-1, pos.iCol-2));
                m_moves.push_back(move);
            }
            else if(board.isEmptySquare(pos.iRow-1, pos.iCol -2)){
                to.iRow = pos.iRow -1;
                to.iCol = pos.iCol -2;
                m_moves.push_back(Move(pos, to, KNIGHT));
            }
        }
        if(pos.iCol + 2 >= 0){
            Position to;
            if(isupper(board.getPieceAtLocation(pos.iRow-1, pos.iCol+2))){
                to.iRow = pos.iRow -1;
                to.iCol = pos.iCol +2;
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow-1, pos.iCol+2));
                m_moves.push_back(move);
            }
            else if(board.isEmptySquare(pos.iRow-1, pos.iCol +2)){
                to.iRow = pos.iRow -1;
                to.iCol = pos.iCol +2;
                m_moves.push_back(Move(pos, to, KNIGHT));
            }
        }
    }
    if(pos.iRow + 2 <= 7){
        if(pos.iCol - 1 >= 0){
            Position to;
            if(isupper(board.getPieceAtLocation(pos.iRow+2, pos.iCol-1))){
                to.iRow = pos.iRow +2;
                to.iCol = pos.iCol -1;
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow+2, pos.iCol-1));
                m_moves.push_back(move);
            }
            else if(board.isEmptySquare(pos.iRow+2, pos.iCol -1)){
                to.iRow = pos.iRow +2;
                to.iCol = pos.iCol -1;
                m_moves.push_back(Move(pos, to, KNIGHT));
            }
        }
        if(pos.iCol + 1 >= 0){
            Position to;
            if(isupper(board.getPieceAtLocation(pos.iRow+2, pos.iCol+1))){
                to.iRow = pos.iRow +2;
                to.iCol = pos.iCol +1;
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow+2, pos.iCol+1));
                m_moves.push_back(move);
            }
            else if(board.isEmptySquare(pos.iRow+2, pos.iCol +1)){
                to.iRow = pos.iRow +2;
                to.iCol = pos.iCol +1;
                m_moves.push_back(Move(pos, to, KNIGHT));
            }
        }
    }
    if(pos.iRow + 1<= 7){
        if(pos.iCol - 2 >= 0){
            Position to;
            if(isupper(board.getPieceAtLocation(pos.iRow+1, pos.iCol-2))){
                to.iRow = pos.iRow +1;
                to.iCol = pos.iCol -2;
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow+1, pos.iCol-2));
                m_moves.push_back(move);
            }
            else if(board.isEmptySquare(pos.iRow+1, pos.iCol -2)){
                to.iRow = pos.iRow +1;
                to.iCol = pos.iCol -2;
                m_moves.push_back(Move(pos, to, KNIGHT));
            }
        }
        if(pos.iCol + 2 >= 0){
            Position to;
            if(isupper(board.getPieceAtLocation(pos.iRow+1, pos.iCol+2))){
                to.iRow = pos.iRow +1;
                to.iCol = pos.iCol +2;
                Move move = Move(pos, to, KNIGHT);
                move.setCapturedPieceType(board.getPieceAtLocation(pos.iRow+1, pos.iCol+2));
                m_moves.push_back(move);
            }
            else if(board.isEmptySquare(pos.iRow+1, pos.iCol +2)){
                to.iRow = pos.iRow +1;
                to.iCol = pos.iCol +2;
                m_moves.push_back(Move(pos, to, KNIGHT));
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
    while((row-i >= 0) && cont){ // moving forward (to white side)
        if((board.isEmptySquare(row -i, pos.iCol))){
            to.iRow = row - i;
            m_moves.push_back(Move(pos, to, type));
            i++;
        }
        else if(isupper(board.getPieceAtLocation(row-i, pos.iCol))){
            to.iRow = row - i;
            Move move = Move(pos, to), type;
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
        else if(isupper(board.getPieceAtLocation(row+i, pos.iCol))){
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
    while((col-i >= 0) && cont){ // moving forward (to white side)
        if((board.isEmptySquare(pos.iRow, col-i))){
            to.iCol = col - i;
            m_moves.push_back(Move(pos, to, type));
            i++;
        }
        else if(isupper(board.getPieceAtLocation(pos.iRow, col-i))){
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
        else if(isupper(board.getPieceAtLocation(pos.iRow, col+i))){
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
    while(cont){
        Position to;
        if((row+rowOffset) <= 7){
            if((col + colOffset <= 7) && rightback){
                if(isupper(board.getPieceAtLocation(row+rowOffset, col+colOffset))){
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
                if(isupper(board.getPieceAtLocation(row+rowOffset, col-colOffset))){
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
                if(isupper(board.getPieceAtLocation(row-rowOffset, col+colOffset))){
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
                if(isupper(board.getPieceAtLocation(row-rowOffset, col-colOffset))){
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
