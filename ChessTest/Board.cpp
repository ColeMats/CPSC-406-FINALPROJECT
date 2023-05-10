#include "Board.h"



Board::Board(){
    memcpy(m_board, initial_board, sizeof(char)*8*8);
    queenActive = false;
    logAllPiecesOnBoard();
    activePlayer = WHITE;
    
    
}

Board::Board(char board[8][8]){
    memcpy(m_board, board, sizeof(char)*8*8);
    queenActive = false;
    logAllPiecesOnBoard();
    activePlayer = WHITE;

}

Board::Board(char board[8][8], Color activeColor){
    memcpy(m_board, board, sizeof(char)*8*8);
    queenActive = false;
    logAllPiecesOnBoard();
    activePlayer = activeColor;

}

void Board::setActivePlayer(Color player){
    activePlayer = player;
}

Color Board::getActivePlayer(){
    return activePlayer;
}

char Board::getPieceAtLocation(int row, int col){
    return m_board[row][col];
}

bool Board::isQueenActive(Color color){
    return queenActive;
}

Color Board::getColorAtLoc(int row, int col){
    char piece = getPieceAtLocation(row, col);
    if(isupper(piece)){
        return WHITE;
    }
    else if(islower(piece)){
        return BLACK;
    }
    return EMPTY;

}

bool Board::isEmptySquare(int row, int col){
    if(m_board[row][col] == 0x20){
        return true;
    }
    return false;
}

bool Board::isSameSquare(int row, int col, Position target){
    return target.iRow == row && target.iCol == col;
}

bool Board::inBounds(int row, int col){
    return row < 8 && row >= 0 && col < 8 && col >=0;
}

Color Board::getOppositeColor(Color color){
    if (color == WHITE){
        return BLACK;
    }
    return WHITE;
}

bool Board::colorIsInCheck(Color color){
    Position kingPos = getKingLocations(color);
    Color oppColor = getOppositeColor(color);
    if(getPawnAttacks(oppColor, kingPos)) return true;
    if(getRookAttacks(oppColor, kingPos)) return true;
    if(getBishopAttacks(oppColor, kingPos)) return true;
    if(getKnightAttacks(oppColor, kingPos)) return true;
    if(getQueenAttacks(oppColor, kingPos)) return true;
    // add king attacks
    return false;
}

bool Board::getPawnAttacks(Color color, Position targetPos){ // color = attacking color
    // checking white attacks on black 
    if(color == WHITE){
        for(int i=0; i<playerPawnPos.size(); ++i){
            if(squareCanAttack(playerPawnPos[i], targetPos, PATTACK, color)) return true;
        }
    }
    else{
        for(int i=0; i<pawnPos.size(); ++i){
            if(squareCanAttack(pawnPos[i], targetPos, PATTACK, color)) return true;
        }
    }
    
    return false;
}

/*
checks if rook can attack a piece at a specific position (color = attack color, targetPos = playing color)
*/
bool Board::getRookAttacks(Color color, Position targetPos){
    if(color == WHITE){
        for(int i=0; i<playerRookPos.size(); ++i){
            if(squareCanAttack(playerRookPos[i], targetPos, HORIZONTAL, color)) return true;
            if(squareCanAttack(playerRookPos[i], targetPos, VERTICAL, color)) return true;
        }
    }
    else{
        for(int i=0; i<rookPos.size(); ++i){
            if(squareCanAttack(rookPos[i], targetPos, HORIZONTAL, color)) return true;
            if(squareCanAttack(rookPos[i], targetPos, VERTICAL, color)) return true;
        }
    }
    return false;
}

bool Board::getBishopAttacks(Color color, Position targetPos){
    if(color == WHITE){
        for(int i=0; i<playerBishopPos.size(); ++i){
            if(squareCanAttack(playerBishopPos[i], targetPos, DIAGONAL, color)) return true;
        }
    }
    else{
        for(int i=0; i<bishopPos.size(); ++i){
            if(squareCanAttack(bishopPos[i], targetPos, DIAGONAL, color)) return true;
        }
    }
    return false;
}

bool Board::getKnightAttacks(Color color, Position targetPos){
    if(color == WHITE){
        for(int i=0; i<playerKnightPos.size(); ++i){
            if(squareCanAttack(playerKnightPos[i], targetPos, LSHAPE, color)) return true;
        }
    }
    else{
        for(int i=0; i<knightPos.size(); ++i){
            if(squareCanAttack(knightPos[i], targetPos, LSHAPE, color)) return true;
        }
    }
    return false;
}

bool Board::getQueenAttacks(Color color, Position targetPos){
    if(color == WHITE){
        if(squareCanAttack(playerQueenPos, targetPos, DIAGONAL, color)) return true;
        if(squareCanAttack(playerQueenPos, targetPos, HORIZONTAL, color)) return true;
        if (squareCanAttack(playerQueenPos, targetPos, VERTICAL, color)) return true;
    }
    else{
        if(squareCanAttack(queenPos, targetPos, DIAGONAL, color)) return true;
        if(squareCanAttack(queenPos, targetPos, HORIZONTAL, color)) return true;
        if (squareCanAttack(queenPos, targetPos, VERTICAL, color)) return true;
    }

    return false;
}

bool Board::squareCanAttack(Position attackPos, Position targetPos, Direction attackDir, Color attackColor){
    int i = attackPos.iRow;
    int j = attackPos.iCol;
    if(attackDir == PATTACK){
        if(attackColor == WHITE){
            if(inBounds(i+1, j+1) && isSameSquare(i+1, j+1, targetPos)){
                return true;
            }
            else if(inBounds(i+1, j-1) && isSameSquare(i+1, j-1, targetPos)){
                return true;
            }
        }
        else{
            if(inBounds(i - 1, j -1) && isSameSquare(i-1, j-1, targetPos)){
                return true;
            }
            else if(inBounds(i - 1, j +1) && isSameSquare(i-1, j+1, targetPos)){
                return true;
            }
        }
    }
    else if(attackDir == DIAGONAL){
        int k = 1;
        
        // forward right (in POV of black) -- decreasing row, increasing col
        while(inBounds(i - k, j + k)){
            if(isSameSquare(i-k, j+k, targetPos)){
                return true;
            }
            else if(!isEmptySquare(i-k, j+k)){
                break;
            }
            ++k;
            
        }
        //forward left (dec row, dec col)
        k = 1;
        while(inBounds(i - k, j-k)){
            if(isSameSquare(i-k, j-k, targetPos)){
                return true;
            }
            else if(!isEmptySquare(i-k, j-k)){
                break;
            }
            ++k;
        }
        // backwards right (inc row, inc col)
        k = 1;
        while(inBounds(i + k, j+k)){
            if(isSameSquare(i+k, j+k, targetPos)){
                return true;
            }
            else if(!isEmptySquare(i+k, j+k)){
                break;
            }
            ++k;
        }
        //backwards left (inc row, dec col)
        k = 1;
        while(inBounds(i + k, j-k)){
            if(isSameSquare(i+k, j-k, targetPos)){
                return true;
            }
            else if(!isEmptySquare(i+k, j-k)){
                break;
            }
            ++k;
        }
    }
    else if(attackDir == HORIZONTAL){
        int k = 0;
        // check right
        while(inBounds(i + ++k, j)){
            if(isSameSquare(i + k, j, targetPos)){
                return true;
            }
            else if(!isEmptySquare(i + k, j)){
                break;
            }
        }
        // check left
        k = 0;
        while(inBounds(i - ++k, j)){
            if(isSameSquare(i - k, j, targetPos)){
                return true;
            }
            else if(!isEmptySquare(i - k, j)){
                break;
            }
        }
    }

    else if(attackDir == VERTICAL){
        int k = 0;
        // down, technically (POV black)
        while(inBounds(i, j + ++k)){
            if(isSameSquare(i, j+k, targetPos)){
                return true;
            }
            else if(!isEmptySquare(i, j+k)){
                break;
            }
        }
        //up POV black
        k=0;
        while(inBounds(i, j - ++k)){
            if(isSameSquare(i, j-k, targetPos)){
                return true;
            }
            else if(!isEmptySquare(i, j-k)){
                break;
            }
        }
    }
    else if(attackDir == LSHAPE){
        for(int n=0; n<8; ++n){
            if(inBounds(i+knighRowOffsets[n], j+knightColOffsets[n]) && isSameSquare(i+knighRowOffsets[n], j+knightColOffsets[n], targetPos)){
                return true;
            }
        }
    }

    return false;
}

void Board::printBoard(){
    for(int i = 0; i<8;++i){
        for(int j = 0; j<8;++j){
            std::cout << m_board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::logAllPiecesOnBoard(){
    for(int i = 0; i<8; ++i){
        for(int j = 0; j<8;++j){
            Position p;
            char temp = m_board[i][j];
            if(islower(temp)){
                switch(temp){
                    case 'p':
                        p.iRow = i;
                        p.iCol = j;
                        pawnPos.push_back(p);
                        break;
                    case 'n':
                        p.iRow = i;
                        p.iCol = j;
                        knightPos.push_back(p);
                        break;
                    case 'r':
                        p.iRow = i;
                        p.iCol = j;
                        rookPos.push_back(p);
                        break;
                    case 'b':
                        p.iRow = i;
                        p.iCol = j;
                        bishopPos.push_back(p);
                        break;
                    case 'q':
                        queenActive = true;
                        p.iRow = i;
                        p.iCol = j;
                        queenPos = p;
                        break;
                    case 'k':
                        p.iRow = i;
                        p.iCol = j;
                        kingPos = p;
                        break;
                    default:
                        break;
                }
            }
            if(isupper(temp)){
                switch(temp){
                    case 'P':
                        p.iRow = i;
                        p.iCol = j;
                        playerPawnPos.push_back(p);
                        break;
                    case 'N':
                        p.iRow = i;
                        p.iCol = j;
                        playerKnightPos.push_back(p);
                        break;
                    case 'R':
                        p.iRow = i;
                        p.iCol = j;
                        playerRookPos.push_back(p);
                        break;
                    case 'B':
                        p.iRow = i;
                        p.iCol = j;
                        playerBishopPos.push_back(p);
                        break;
                    case 'Q':
                        queenActive = true;
                        p.iRow = i;
                        p.iCol = j;
                        playerQueenPos = p;
                        break;
                    case 'K':
                        p.iRow = i;
                        p.iCol = j;
                        playerKingPos = p;
                        break;
                    default:
                        break;
                }
            }

        }
    }
}

void Board::doMove(Move move){
    Position moveFrom = move.getFrom();
    Position moveTo = move.getTo();
    char piece = getPieceAtLocation(moveFrom.iRow, moveFrom.iCol);
    m_board[moveFrom.iRow][moveFrom.iCol] = 0x20;
    m_board[moveTo.iRow][moveTo.iCol] = piece;
}



std::vector<Position> Board::getPawnLocations(Color pieceColor){
    if(pieceColor == WHITE)
        return playerPawnPos;
    return pawnPos;
}

std::vector<Position> Board::getRookLocations(Color pieceColor){
    if(pieceColor == WHITE)
        return playerRookPos;
    return rookPos;
}

std::vector<Position> Board::getBishopLocations(Color pieceColor){
    if(pieceColor == WHITE)
        return playerBishopPos;
    return bishopPos;
}

std::vector<Position> Board::getKnightLocations(Color pieceColor){
    if(pieceColor == WHITE)
        return playerKnightPos;
    return knightPos;
}

Position Board::getQueenLocations(Color pieceColor){
    if(pieceColor == WHITE)
        return playerQueenPos;
    return queenPos;
}

Position Board::getKingLocations(Color pieceColor){
    if(pieceColor == WHITE)
        return playerKingPos;
    return kingPos;
}

TreeNode* Board::getTreeNode() {
    return m_treeNode;
}

void Board::setTreeNode(TreeNode* treeNode) {
    m_treeNode = treeNode;
}
