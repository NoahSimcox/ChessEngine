#ifndef UNTITLED_CHESSPIECES_H
#define UNTITLED_CHESSPIECES_H

#include <stdbool.h>

#define ROW 8
#define COL 7

typedef enum { empty = 0, pawn = 1 , bishop = 2, knight = 3, rook = 5, queen = 9, king = 100} piece_type;

typedef struct {
    bool isWhite;
    piece_type type;
    int x;
    int y;
} Piece;

Piece (*possible_moves(Piece))[COL];

#endif //UNTITLED_CHESSPIECES_H
