#include <stdio.h>
#include "chessPieces.h"
#include "chessBoard.h"

int main() {

    Piece* newBoard = new_board();

    Piece piece = {false, knight, 4, 4 };
    Piece* ptr = possible_moves(piece);

//    for (int i = 0; i < 27; i++) {
//        printf("possibles moves [%d, %d]\n", (ptr + i)->x, (ptr + i)->type);
//    }
    for (int i = 0; i < 32; i++) {
        printf("current pieces - type:%d pos: [%d, %d]\n", (newBoard + i)->type, (newBoard + i)->x, (newBoard + i)->y);
    }
}
