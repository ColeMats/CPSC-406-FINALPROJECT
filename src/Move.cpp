
#include "Move.h"

Move::Move(){
    m_from = Position();
    m_to = Position();
    m_capturedType = 0x20;
    m_value = 0;
}


Move::Move(Position from, Position to){
    m_from = from;
    m_to = to;
    m_capturedType = 0x20;
    m_value = 0;
}

Move::Move(Position from, Position to, PieceType type){
    m_from = from;
    m_to = to;
    m_pieceType = type;
    m_capturedType = 0x20;
    m_value = 0;
}

Position Move::getFrom(){
    return m_from;
}

Position Move::getTo(){
    return m_to;
}

void Move::setCapturedPieceType(char piece){
    m_capturedType = piece;
    switch (piece){
        case 'p':
        case 'P':
            m_value = 1;
            break;
        case 'r':
        case 'R':
            m_value = 5;
            break;
        case 'n':
        case 'N':
            m_value = 3;
            break;
        case 'b':
        case 'B':
            m_value = 3;
            break;
        case 'q':
        case 'Q':
            m_value = 9;
            break;
        default:
            break;
    }
}

char Move::getCapturedPieceType(){
    return m_capturedType;
}

void Move::setMoveValue(int value){
    m_value = value;
}

int Move::getMoveValue(){
    return m_value;
}

PieceType Move::getPieceType(){
    return m_pieceType;
}

void Move::printPieceType(){
    switch(m_pieceType){
        case PieceType::PAWN:
            std::cout << "Pawn: " ;
            break;
        case PieceType::ROOK:
            std::cout << "Rook: ";
            break;
        case PieceType::KNIGHT:
            std::cout << "Knight: ";
            break;
        case PieceType::BISHOP:
            std::cout << "Bishop: ";
            break;
        case PieceType::QUEEN:
            std::cout << "Queen: ";
            break;
        case PieceType::KING:
            std::cout << "King: ";
            break;
        default:
            break;
    }
}

std::string Move::toNotation() const {
    std::string uci = "";
    uci += static_cast<char>(m_from.iCol + 'A');
    uci += static_cast<char>(m_from.iRow + '1');
    uci += "-";
    uci += static_cast<char>(m_to.iCol + 'A');
    uci += static_cast<char>(m_to.iRow + '1');
    return uci;
}