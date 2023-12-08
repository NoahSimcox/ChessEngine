#include "chessPieces.h"

#define ROW 8
#define COL 7

Piece (*possible_moves(Piece p))[COL] { // given the board is empty

    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int q;

    static Piece moves[ROW][COL];
    Piece temp = { p.isWhite, p.type, p.x, p.y };

    switch (p.type) {

        case pawn:
            if (p.isWhite && p.y == 6) {
                temp.y -= 2;
                moves[0][1] = temp;
                temp.y = p.y;
            } if (p.isWhite) {
                temp.y--;
                moves[0][0] = temp;
            }

            if (!(p.isWhite) && p.y == 1) {
                temp.y += 2;
                moves[0][1] = temp;
                temp.y = p.y;
            } if (!(p.isWhite)) {
                temp.y++;
                moves[0][0] = temp;
            }
            break;

        case bishop:
            for (i = 0; i < 7; i++){
                temp.x++;
                temp.y++;

                if (temp.x > 7 || temp.y > 7)
                    break;

                moves[0][i] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (j = 0; j < 7; j++){
                temp.x++;
                temp.y--;

                if (temp.x > 7 || temp.y < 0)
                    break;

                moves[1][j] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (k = 0; k < 7; k++){
                temp.x--;
                temp.y--;

                if (temp.x < 0 || temp.y < 0)
                    break;

                moves[2][k] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (l = 0; l < 7; l++){
                temp.x--;
                temp.y++;

                if (temp.x < 0 || temp.y > 7)
                    break;

                moves[3][l] = temp;
            }
            break;

        case rook:
            for (i = 0; i < 7; i++){
                temp.x++;

                if (temp.x > 7)
                    break;

                moves[0][i] = temp;
            }

            temp.x = p.x;

            for (j = 0; j < 7; j++){
                temp.y--;

                if (temp.y < 0)
                    break;

                moves[1][j] = temp;
            }

            temp.y = p.y;

            for (k = 0; k < 7; k++){
                temp.x--;

                if (temp.x < 0)
                    break;

                moves[2][k] = temp;
            }

            temp.x = p.x;

            for (l = 0; l < 7; l++){
                temp.y++;

                if (temp.y > 7)
                    break;

                moves[3][l] = temp;
            }
            break;

        case queen:
            for (i = 0; i < 7; i++){
                temp.x++;
                temp.y++;

                if (temp.x > 7 || temp.y > 7)
                    break;

                moves[0][i] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (j = 0; j < 7; j++){
                temp.x++;
                temp.y--;

                if (temp.x > 7 || temp.y < 0)
                    break;

                moves[1][j] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (k = 0; k < 7; k++){
                temp.x--;
                temp.y--;

                if (temp.x < 0 || temp.y < 0)
                    break;

                moves[2][k] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (l = 0; l < 7; l++){
                temp.x--;
                temp.y++;

                if (temp.x < 0 || temp.y > 7)
                    break;

                moves[3][l] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (m = 0; m < 7; m++){
                temp.x++;

                if (temp.x > 7)
                    break;

                moves[4][m] = temp;
            }

            temp.x = p.x;

            for (n = 0; n < 7; n++){
                temp.y--;

                if (temp.y < 0)
                    break;

                moves[5][n] = temp;
            }

            temp.y = p.y;

            for (o = 0; o < 7; o++){
                temp.x--;

                if (temp.x < 0)
                    break;

                moves[6][o] = temp;
            }

            temp.x = p.x;

            for (q = 0; q < 7; q++){
                temp.y++;

                if (temp.y > 7)
                    break;

                moves[7][q] = temp;
            }
            break;

        case knight:
            temp.x += 2;
            temp.y++;

            if (temp.x <= 7 && temp.y <= 7)
                moves[0][0] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x += 2;
            temp.y--;

            if (temp.x <= 7 && temp.y >= 0)
                moves[1][0] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x++;
            temp.y -= 2;

            if (temp.x <= 7 && temp.y >= 0)
                moves[2][0] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x--;
            temp.y -= 2;

            if (temp.x >= 0 && temp.y >= 0)
                moves[3][0] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x -= 2;
            temp.y++;

            if (temp.x >= 0 && temp.y <= 7)
                moves[4][0] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x -= 2;
            temp.y--;

            if (temp.x >= 0 && temp.y >= 0)
                moves[5][0] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x--;
            temp.y += 2;

            if (temp.x >= 0 && temp.y <= 7)
                moves[6][0] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x++;
            temp.y += 2;

            if (temp.x <= 7 && temp.y <= 7)
                moves[7][0] = temp;

            break;

        case king:
            temp.x++;
            if (temp.x <= 7)
                moves[0][0] = temp;

            temp.x = p.x;

            temp.x++;
            temp.y--;
            if (temp.x <= 7 && temp.y >= 0)
                moves[1][0] = temp;

            temp.x = p.x;
            temp.y = p.y;

            temp.y--;
            if (temp.y >= 0)
                moves[2][0] = temp;

            temp.y = p.y;

            temp.x--;
            temp.y--;
            if (temp.x >= 0 && temp.y >= 0)
                moves[3][0] = temp;

            temp.x = p.x;
            temp.y = p.y;

            temp.x--;
            if (temp.x >= 0)
                moves[4][0] = temp;

            temp.x = p.x;

            temp.x--;
            temp.y++;
            if (temp.x >= 0 && temp.y <= 7)
                moves[5][0] = temp;

            temp.x = p.x;
            temp.y = p.y;

            temp.y++;
            if (temp.y <= 7)
                moves[6][0] = temp;

            temp.x = p.x;
            temp.y = p.y;

            temp.x++;
            temp.y++;
            if (temp.x <= 7 && temp.y <= 7)
                moves[7][0] = temp;

            break;

        case empty:
            break;
    }

    return moves;
}