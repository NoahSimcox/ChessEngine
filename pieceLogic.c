#include "pieceLogic.h"
#include "chessPieces.h"
#include "chessBoard.h"

Piece* possible_moves_prune(Piece(*possibleMoves)[COL]){

    Piece* currBoard = new_board();

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {

            if (possibleMoves[i][j].x){

            }
        }
    }

}