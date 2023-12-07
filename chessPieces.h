#ifndef UNTITLED_CHESSPIECES_H
#define UNTITLED_CHESSPIECES_H

#include <stdbool.h>

typedef enum { pawn, bishop, knight, rook, queen, king, empty } piece_type;

typedef struct {
    bool isWhite;
    piece_type type;
    int x;
    int y;
} Piece;

Piece* possible_moves(Piece);

#endif //UNTITLED_CHESSPIECES_H
