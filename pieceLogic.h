#ifndef UNTITLED_PIECELOGIC_H
#define UNTITLED_PIECELOGIC_H

#include "chessPieces.h"

Piece* possible_moves_prune(Piece(*possibleMoves)[COL], Piece currPieces[32], bool canEnPassant, Piece newPawnMove[1]);

bool canEnPassant(Piece currMove[2], Piece currPieces[32], Piece newMove[1]);

#endif //UNTITLED_PIECELOGIC_H
