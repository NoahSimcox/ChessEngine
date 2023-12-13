#include "pieceLogic.h"
#include "chessPieces.h"
#include "chessBoard.h"
#include "stdio.h"

Piece* possible_moves_prune(Piece(*possibleMoves)[COL], Piece currPieces[32]){


    static Piece newPossibleMoves[27];

    if (possibleMoves[0][0].type == empty)
        return newPossibleMoves;

    int row = 0;
    int col = 0;

    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 32; j++) {

            if (col == 0 && possibleMoves[0][0].type != pawn && possibleMoves[row][col].type == empty)
                return newPossibleMoves;

            if (possibleMoves[0][0].type == pawn && possibleMoves[row][col].type == empty)
                return newPossibleMoves;
            else if (possibleMoves[row][col].type == empty){
                row++;
                col = 0;
                break;
            }

            switch (possibleMoves[0][0].type) {
                default:
                    if ((currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].isWhite == currPieces[j].isWhite) || (currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].type == pawn)){
                        if (row == 7)
                            return newPossibleMoves;
                        row++;
                        col = 0;
                        i -= 1; // do this as to not increase the index of newPossibleMoves
                        goto exitLoop;
                    } else if (currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].isWhite != currPieces[j].isWhite && possibleMoves[0][0].type != pawn){
                        newPossibleMoves[i] = possibleMoves[row][col];
                        if (row == 7)
                            return newPossibleMoves;
                        row++;
                        col = 0;
                        goto exitLoop;
                    }
            }


            // pawn taking being hard coded
            if (possibleMoves[0][0].type == pawn && currPieces[j].x == (possibleMoves[0][0].x + 1) && currPieces[j].y == possibleMoves[0][0].y){
                Piece temp = {possibleMoves[0][0].isWhite, pawn, possibleMoves[0][0].x + 1, possibleMoves[0][0].y};
                newPossibleMoves[2] = temp;
            }
            if (possibleMoves[0][0].type == pawn && currPieces[j].x == (possibleMoves[0][0].x - 1) && currPieces[j].y == possibleMoves[0][0].y){
                Piece temp = {possibleMoves[0][0].isWhite, pawn, possibleMoves[0][0].x - 1, possibleMoves[0][0].y};
                newPossibleMoves[3] = temp;
            }

        }

        if (possibleMoves[0][0].type != knight && possibleMoves[0][0].type != king) {
            newPossibleMoves[i] = possibleMoves[row][col];
            col++;
        } else {
            newPossibleMoves[i] = possibleMoves[row][col];
            row++;
        }

        exitLoop:
    }

    return newPossibleMoves;
}