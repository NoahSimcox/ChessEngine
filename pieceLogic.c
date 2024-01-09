#include "pieceLogic.h"
#include "chessPieces.h"
#include "chessBoard.h"
#include "stdio.h"
#include "stdbool.h"
#include "arrayClean.h"

Piece* possible_moves_prune(Piece(*possibleMoves)[COL], Piece currPieces[32], bool canEnPassant, Piece newPawnMove[1]){

    static Piece newPossibleMoves[27];

    int row = 0;
    int col = 0;

    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 32; j++) {

            if (col == 0 && possibleMoves[0][0].type != pawn && possibleMoves[row][col].type == empty)
                return newPossibleMoves;

            else if (possibleMoves[row][col].type == empty && possibleMoves[0][0].type != pawn){
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

            if (possibleMoves[row][col].type == empty)
                goto exitLoop;

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

bool check(Piece currPieces[32], Piece currMove[2], bool EnPassant, Piece newPawnMove[1], Piece* Board){

    bool inCheck = false;
    int futureArrSize = 0;
    Piece tempPieces[32];

    for (int i = 0; i < 32; i++){

        tempPieces[i] = currPieces[i];
        printf("type: %d color: %d position: [%d, %d] value: %f\n", (tempPieces + i) -> type, (tempPieces + i) -> isWhite, (tempPieces + i) -> x, (tempPieces + i) -> y, (tempPieces + i) -> value);
    }


    int increment = 0;
    if (!(currMove[0].isWhite))
        increment = 16;


    for (int k = 0; k < 16; k++){

        if (tempPieces[k + increment].type == empty)
            continue;

        Piece piece = {tempPieces[k + increment].isWhite, tempPieces[k + increment].type, tempPieces[k + increment].x, tempPieces[k + increment].y};
        Piece (*ptr)[COL] = possible_moves(piece);
        printf("!!x: %d  Y: %d\n", tempPieces[k + increment].x, tempPieces[k + increment].y);
        Piece *futureMoves = possible_moves_prune(ptr, tempPieces, EnPassant, newPawnMove);
        Piece *futureArr = arrayClean(futureMoves, &futureArrSize);

        if (futureArr[0].type == empty)
            continue;

        printf("size: %d\ninitial position  x: %d  y: %d\n", futureArrSize, tempPieces[k + increment].x, tempPieces[k + increment].y);
        for (int h = 0; h < futureArrSize; h++) {

            printf("x: %d  Y: %d\n", futureArr[h].x, futureArr[h].y);
        }


        for (int j = 0; j < futureArrSize; j++) {

            Piece futureMove[2] = {{futureArr[j].isWhite, futureArr[j].type, tempPieces[k + increment].x, tempPieces[k + increment].y},
                                   {futureArr[j].isWhite, futureArr[j].type, futureArr[j].x, futureArr[j].y}};

            Piece *futureBoard = update_board(futureMove, Board, tempPieces);

            float totalPoints = 0.0f;

            if (currMove[0].isWhite) {
                for (int l = 0; l < 16; l++) {
                    totalPoints += tempPieces[l].value;
                }
            }
            else {
                for (int m = 0; m < 16; m++) {
                    totalPoints += tempPieces[m + 16].value;
                }
            }

            if (totalPoints < 90.0f) {
                printf("balls\n");
                inCheck = true;
                printf("x: %d  y: %d \n", futureArr[j].x, futureArr[j].y);
            }
        }
    }

    return inCheck;
}