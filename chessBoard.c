#include "chessBoard.h"
#include "chessPieces.h"

Piece* new_board(Piece currPieces[32]){

    static Piece currBoard[64];
    int x = 0;
    int y = 0;
    for (int i = 0; i < 32; i++) {
        if (i == 7 || i == 15 || i == 23) {
            x = 0;
            y++;
        }
        else
            x++;
        Piece square = {true, empty, y, x};
        currBoard[i + 32] = square;
    }

    Piece wp1 = {true, pawn, 0, 6};
    Piece wp2 = {true, pawn, 1, 6};
    Piece wp3 = {true, pawn, 2, 6};
    Piece wp4 = {true, pawn, 3, 6};
    Piece wp5 = {true, pawn, 4, 6};
    Piece wp6 = {true, pawn, 5, 6};
    Piece wp7 = {true, pawn, 6, 6};
    Piece wp8 = {true, pawn, 7, 6};

    Piece wr1 = {true, rook, 0, 7};
    Piece wr2 = {true, rook, 7, 7};

    Piece wn1 = {true, knight, 1, 7};
    Piece wn2 = {true, knight, 6, 7};

    Piece wb1 = {true, bishop, 2, 7};
    Piece wb2 = {true, bishop, 5, 7};

    Piece wq = {true, queen, 3, 7};
    Piece wk = {true, king, 4, 7};


    Piece bp1 = {true, pawn, 0, 1};
    Piece bp2 = {true, pawn, 1, 1};
    Piece bp3 = {true, pawn, 2, 1};
    Piece bp4 = {true, pawn, 3, 1};
    Piece bp5 = {true, pawn, 4, 1};
    Piece bp6 = {true, pawn, 5, 1};
    Piece bp7 = {true, pawn, 1, 1};
    Piece bp8 = {true, pawn, 7, 1};

    Piece br1 = {true, rook, 0, 0};
    Piece br2 = {true, rook, 7, 0};

    Piece bn1 = {true, knight, 1, 0};
    Piece bn2 = {true, knight, 6, 0};

    Piece bb1 = {true, bishop, 2, 0};
    Piece bb2 = {true, bishop, 5, 0};

    Piece bq = {true, queen, 3, 0};
    Piece bk = {true, king, 4, 0};
    
    currPieces[0] = wp1;
    currPieces[1] = wp2;
    currPieces[2] = wp3;
    currPieces[3] = wp4;
    currPieces[4] = wp5;
    currPieces[5] = wp6;
    currPieces[6] = wp7;
    currPieces[7] = wp8;
    currPieces[8] = wr1;
    currPieces[9] = wr2;
    currPieces[10] = wn1;
    currPieces[11] = wn2;
    currPieces[12] = wb1;
    currPieces[13] = wb2;
    currPieces[14] = wq;
    currPieces[15] = wk;
    currPieces[16] = bp1;
    currPieces[17] = bp2;
    currPieces[18] = bp3;
    currPieces[19] = bp4;
    currPieces[20] = bp5;
    currPieces[21] = bp6;
    currPieces[22] = bp7;
    currPieces[23] = bp8;
    currPieces[24] = br1;
    currPieces[25] = br2;
    currPieces[26] = bn1;
    currPieces[27] = bn2;
    currPieces[28] = bb1;
    currPieces[29] = bb2;
    currPieces[30] = bq;
    currPieces[31] = bk;
    currBoard[0] = wp1;
    currBoard[1] = wp2;
    currBoard[2] = wp3;
    currBoard[3] = wp4;
    currBoard[4] = wp5;
    currBoard[5] = wp6;
    currBoard[6] = wp7;
    currBoard[7] = wp8;
    currBoard[8] = wr1;
    currBoard[9] = wr2;
    currBoard[10] = wn1;
    currBoard[11] = wn2;
    currBoard[12] = wb1;
    currBoard[13] = wb2;
    currBoard[14] = wq;
    currBoard[15] = wk;
    currBoard[16] = bp1;
    currBoard[17] = bp2;
    currBoard[18] = bp3;
    currBoard[19] = bp4;
    currBoard[20] = bp5;
    currBoard[21] = bp6;
    currBoard[22] = bp7;
    currBoard[23] = bp8;
    currBoard[24] = br1;
    currBoard[25] = br2;
    currBoard[26] = bn1;
    currBoard[27] = bn2;
    currBoard[28] = bb1;
    currBoard[29] = bb2;
    currBoard[30] = bq;
    currBoard[31] = bk;
    
    return currPieces;
}


