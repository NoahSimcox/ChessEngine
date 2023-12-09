#include "pieceLogic.h"
#include "chessPieces.h"
#include "chessBoard.h"

Piece* possible_moves_prune(Piece(*possibleMoves)[COL]){

    Piece currPieces[32];
    new_board(currPieces);
    Piece newPossibleMoves[27];

    if (possibleMoves[0][0].type == empty)
        return newPossibleMoves;

    int row = 0;
    int col = 0;

    for (int i = 0; i < 27; i++) {
        exitLoop:
        for (int j = 0; j < 32; j++) {

            if (col == 0 && possibleMoves[0][0].type != pawn && possibleMoves[row][col].type == empty)
                return newPossibleMoves;

            if (possibleMoves[row][col].type == empty){
                row++;
                col = 0;
                break;
            }

            switch (possibleMoves[0][0].type) {
                case pawn:
                case king:
                case knight:
                    // nothing is done here
                    break;
                default:
                    if (currPieces[j].x == /*make sure to check for color of the piece*/possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y){
                        row++;
                        col = 0;
                        goto exitLoop;
                    }
                    break;
            }





        }
    }
}