#include <stdio.h>
#include "chessPieces.h"
#include "chessBoard.h"
#include "pieceLogic.h"
#include "arrayClean.h"

int main() {

    Piece currMove[2] = {{false, pawn, 5, 1}, {false, pawn, 5, 3}};
    Piece newPawnMove[1];

    Piece currPieces[32];
    new_board(currPieces);

    bool EnPassant = canEnPassant(currMove, currPieces, newPawnMove);

    Piece piece = {true, pawn, 4, 3 };
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
}
