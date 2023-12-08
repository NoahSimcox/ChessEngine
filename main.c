#include <stdio.h>
#include "chessPieces.h"
#include "chessBoard.h"

int main() {

    Piece* newBoard = new_board();

    Piece piece = {true, queen, 4, 4 };
    Piece (*ptr)[COL] = possible_moves(piece);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (ptr[i][j].type == empty)
                printf("nuts");
            printf("column: %d  row: %d  possibles moves [%d, %d]\n", j, i, ptr[i][j].x, ptr[i][j].y);
        }
    }
//    for (int i = 0; i < 32; i++) {
//        printf("current pieces - type:%d pos: [%d, %d]\n", (newBoard + i)->type, (newBoard + i)->x, (newBoard + i)->y);
//    }
}
