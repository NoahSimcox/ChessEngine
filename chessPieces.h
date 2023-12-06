#ifndef UNTITLED_CHESSPIECES_H
#define UNTITLED_CHESSPIECES_H

#include <stdbool.h>

typedef enum { pawn, bishop, knight, rook, queen, king } piece_type;

typedef struct {
    bool isWhite;
    piece_type type;
    int x;
    int y;
} Piece;

#endif //UNTITLED_CHESSPIECES_H
