#include "chessPieces.h"

Piece* possible_moves(Piece p) { // given the board is empty

    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int q;

    Piece moves[27]; // 27 is the largest possible number of moves a piece could make
    Piece temp = { p.isWhite, p.type, p.x, p.y };

    switch (p.type) {

        case pawn:
            if (p.isWhite && p.y == 2) {
                temp.y = p.y + 2;
                moves[1] = temp;
            }
            temp.y = p.y + 1;
            moves[0] = temp;
            break;

        case bishop:
            for (i = 0; i < 7; i++){
                temp.x = p.x + 1;
                temp.y = p.y + 1;

                if (temp.x >= 8 || temp.y >= 8)
                    break;

                moves[i] = temp;
            }
            for (j = i; j < i + 7; j++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x + 1;
                temp.y = p.y - 1;

                if (temp.x >= 8 || temp.y <= 1)
                    break;

                moves[j] = temp;
            }
            for (k = j; k < j + 7; k++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x - 1;
                temp.y = p.y + 1;

                if (temp.x <= 1 || temp.y >= 8)
                    break;

                moves[k] = temp;
            }
            for (l = k; l < k + 7; l++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x - 1;
                temp.y = p.y - 1;

                if (temp.x <= 1 || temp.y <= 1)
                    break;

                moves[l] = temp;
            }
            break;

        case rook:
            for (i = 0; i < 7; i++){
                temp.x = p.x + 1;

                if (temp.x >= 8)
                    break;

                moves[i] = temp;
            }
            for (j = i; j < i + 7; j++){
                temp.x = p.x;
                temp.y = p.y - 1;

                if (temp.y <= 1 )
                    break;

                moves[j] = temp;
            }
            for (k = j; k < j + 7; k++){
                temp.y = p.y;
                temp.x = p.x - 1;

                if (temp.x <= 1)
                    break;

                moves[k] = temp;
            }
            for (l = k; l < k + 7; l++){
                temp.x = p.x;
                temp.y = p.y + 1;

                if (temp.y >= 8)
                    break;

                moves[l] = temp;
            }
            break;

        case queen:
            for (i = 0; i < 7; i++){
                temp.x = p.x + 1;
                temp.y = p.y + 1;

                if (temp.x >= 8 || temp.y >= 8)
                    break;

                moves[i] = temp;
            }
            for (j = i; j < i + 7; j++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x + 1;
                temp.y = p.y - 1;

                if (temp.x >= 8 || temp.y <= 1)
                    break;

                moves[j] = temp;
            }
            for (k = j; k < j + 7; k++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x - 1;
                temp.y = p.y + 1;

                if (temp.x <= 1 || temp.y >= 8)
                    break;

                moves[k] = temp;
            }
            for (l = k; l < k + 7; l++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x - 1;
                temp.y = p.y - 1;

                if (temp.x <= 1 || temp.y <= 1)
                    break;

                moves[l] = temp;
            }
            for (m = l; m < l + 7; m++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x + 1;

                if (temp.x >= 8)
                    break;

                moves[m] = temp;
            }
            for (n = m; n < m + 7; n++){
                temp.x = p.x;
                temp.y = p.y - 1;

                if (temp.y <= 1 )
                    break;

                moves[n] = temp;
            }
            for (o = n; o < n + 7; o++){
                temp.y = p.y;
                temp.x = p.x - 1;

                if (temp.x <= 1)
                    break;

                moves[o] = temp;
            }
            for (q = o; q < o + 7; q++){
                temp.x = p.x;
                temp.y = p.y + 1;

                if (temp.y >= 8)
                    break;

                moves[q] = temp;
            }
            break;

    }

    return moves;
};