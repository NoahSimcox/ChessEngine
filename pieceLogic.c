#include "pieceLogic.h"
#include "chessPieces.h"
#include "chessBoard.h"
#include "stdio.h"
#include "stdbool.h"

Piece* possible_moves_prune(Piece(*possibleMoves)[COL], Piece currPieces[32], bool canEnPassant, Piece newPawnMove[1], bool inCheck){


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

            if ((currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].isWhite == currPieces[j].isWhite) || (currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].type == pawn) && currPieces[j].type != empty){
                if (row == 7)
                    return newPossibleMoves;
                row++;
                col = 0;
                i -= 1; // do this as to not increase the index of newPossibleMoves
                goto exitLoop;
            } else if (currPieces[j].x == possibleMoves[row][col].x && currPieces[j].y == possibleMoves[row][col].y && possibleMoves[0][0].isWhite != currPieces[j].isWhite && possibleMoves[0][0].type != pawn && currPieces[j].type != empty){
                newPossibleMoves[i] = possibleMoves[row][col];
                if (row == 7)
                    return newPossibleMoves;
                row++;
                col = 0;
                goto exitLoop;
            }


            // pawn stuff being hard coded
            if (possibleMoves[0][0].type == pawn && currPieces[j].x == (possibleMoves[0][0].x + 1) && currPieces[j].y == possibleMoves[0][0].y && currPieces[j].type != empty){
                Piece temp = {possibleMoves[0][0].isWhite, pawn, possibleMoves[0][0].x + 1, possibleMoves[0][0].y};
                newPossibleMoves[2] = temp;
            }
            if (possibleMoves[0][0].type == pawn && currPieces[j].x == (possibleMoves[0][0].x - 1) && currPieces[j].y == possibleMoves[0][0].y && currPieces[j].type != empty){
                Piece temp = {possibleMoves[0][0].isWhite, pawn, possibleMoves[0][0].x - 1, possibleMoves[0][0].y};
                newPossibleMoves[3] = temp;
            }
            if (possibleMoves[0][0].type == pawn && canEnPassant && currPieces[j].type != empty){
                printf("testing");
                newPossibleMoves[4] = newPawnMove[0];
            }

        }

        if (possibleMoves[0][0].type != knight && possibleMoves[0][0].type != king) {
            newPossibleMoves[i] = possibleMoves[row][col];

            if (col == 6) {
                row++;
                col = 0;
            } else
                col++;

        } else {
            newPossibleMoves[i] = possibleMoves[row][col];

            if (row == 7)
                return newPossibleMoves;

            row++;
        }

        exitLoop:
    }

    return newPossibleMoves;
}


bool canEnPassant(Piece currMove[2], Piece currPieces[32], Piece newMove[1]){
    if (currMove[0].y - currMove[1].y == 2 || currMove[0].y - currMove[1].y == -2){
        for (int i = 0; i < 32; i++){

            int type = currPieces[i].type;
            bool isWhite = currPieces[i].isWhite;
            int pieceX = currPieces[i].x;
            int pieceY = currPieces[i].y;
            int moveX = currMove[1].x;
            int moveY = currMove[1].y;

            if (isWhite != currMove[1].isWhite && type == pawn && (pieceX == moveX + 1 || pieceX == moveX - 1) && (pieceY == moveY)){
                if (currPieces[i].isWhite) {
                    Piece temp = {currPieces[i].isWhite, pawn, currMove[1].x, currMove[1].y - 1};
                    newMove[0] = temp;
                } else {
                    Piece temp = {currPieces[i].isWhite, pawn, currMove[1].x, currMove[1].y + 1};
                    newMove[0] = temp;
                }

                return true;
            }
        }
    }
    return false;
}

bool check()