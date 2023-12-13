#ifndef UNTITLED_PIECELOGIC_H
#define UNTITLED_PIECELOGIC_H

#include "chessPieces.h"

Piece* possible_moves_prune(Piece(*possibleMoves)[COL], Piece currPieces[32]);

#endif //UNTITLED_PIECELOGIC_H
