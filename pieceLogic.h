#ifndef UNTITLED_PIECELOGIC_H
#define UNTITLED_PIECELOGIC_H

#include "chessPieces.h"

Piece* possible_moves_prune(Piece(*possibleMoves)[COL], Piece currPieces[32], bool canEnPassant, Piece newPawnMove[1]/*, bool inCheck*/);

bool canEnPassant(Piece currMove[2], Piece currPieces[32], Piece newMove[1]);

bool check(Piece currPieces[32], Piece currMove[2], bool EnPassant, Piece newPawnMove[1], Piece* Board);

#endif //UNTITLED_PIECELOGIC_H
