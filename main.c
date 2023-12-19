#include <stdio.h>
#include "chessPieces.h"
#include "chessBoard.h"
#include "pieceLogic.h"
#include "arrayClean.h"

int main() {

    Piece currPieces[32];
    Piece* Board = new_board(currPieces);

    Piece currMove[2] = {{true, queen, 5, 4}, {true, queen, 2, 4}};

    Piece newPawnMove[1];
    bool EnPassant = canEnPassant(currMove, currPieces, newPawnMove);

    Piece* newBoard = update_board(currMove, Board, currPieces);

    Piece piece = {false, knight, 2, 5 };
    Piece (*ptr)[COL] = possible_moves(piece);
    Piece* newMoves = possible_moves_prune(ptr, currPieces, EnPassant, newPawnMove);


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (ptr[i][j].type == empty)
                printf("nuts");
            printf("column: %d  row: %d  possibles moves [%d, %d]\n", j, i, ptr[i][j].x, ptr[i][j].y);
        }
    }

    for (int l = 0; l < 27; l++) {
        printf("type: %d possible move: [%d, %d]\n", (newMoves + l) -> type, (newMoves + l) -> x, (newMoves + l) -> y);
    }

    int count = 0;
    Piece* finalArr = arrayClean(newMoves, &count);
    for (int m = 0; m < count; m++) {
        printf("type: %d new possible move: [%d, %d]\n", (finalArr + m) -> type, (finalArr + m) -> x, (finalArr + m) -> y);
    }

    for (int j = 0; j < 32; j++) {
        printf("value: %d color: %d position: [%d, %d]\n", (currPieces + j) -> type, (currPieces + j) -> isWhite, (currPieces + j) -> x, (currPieces + j) -> y);
    }
}
