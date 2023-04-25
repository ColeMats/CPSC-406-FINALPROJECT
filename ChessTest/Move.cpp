
#include "Move.h"

Move::Move(){
    m_from = Position();
    m_to = Position();
}

Move::Move(Position from, Position to){
    m_from = from;
    m_to = to;
}

Move::Move(Position from, Position to, PieceType type){
    m_from = from;
    m_to = to;
    m_pieceType = type;
}

Position Move::getFrom(){
    return m_from;
}

Position Move::getTo(){
    return m_to;
}

void Move::setCapturedPieceType(char piece){
    m_capturedType = piece;
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