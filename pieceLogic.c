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
                    if (currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].type == currPieces[j].type){
                        row++;
                        col = 0;
                        goto exitLoop;
                    } else if (currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].type != currPieces[j].type){
                        newPossibleMoves[i] = possibleMoves[row][col];
                        row++;
                        col = 0;
                        goto exitLoop;
                    } else {
                        newPossibleMoves[i] = possibleMoves[row][col];
                        col++;
                        goto exitLoop;
                    }
            }

            switch (possibleMoves[0][0].type) {
                case pawn:
                case queen:
                case rook:
                case bishop:
                    // nothing is done here
                    break;
                default:
                    if (currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].type == currPieces[j].type){
                        row++;
                        col = 0;
                        goto exitLoop;
                    } else if (currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].type != currPieces[j].type){
                        newPossibleMoves[i] = possibleMoves[row][col];
                        col++;
                        goto exitLoop;
                    }
                    break;
            }



        }


        exitLoop:
    }

    return newPossibleMoves;
}