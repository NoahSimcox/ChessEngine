#ifndef UNTITLED_CHESSPIECES_H
#define UNTITLED_CHESSPIECES_H

#include <stdbool.h>

#define ROW 8
#define COL 7

typedef enum { empty, pawn, bishop, knight, rook, queen, king } piece_type;

typedef struct {
    bool isWhite;
    piece_type type;
    int x;
    int y;
} Piece;

Piece (*possible_moves(Piece))[COL];

#endif //UNTITLED_CHESSPIECES_H
