#ifndef UNTITLED_CHESSBOARD_H
#define UNTITLED_CHESSBOARD_H
#include "chessPieces.h"

Piece* new_board(Piece currPieces[32]);

Piece* update_board(Piece move[2], Piece currBoard[64], Piece currPieces[32]);

#endif //UNTITLED_CHESSBOARD_H
