#include "chessPieces.h"

#define ROW 8
#define COL 7

Piece (*possible_moves(Piece p))[COL] { // given the board is empty

    int rowChecker = 0;
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

                moves[rowChecker][i] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            for (j = 0; j < 7; j++){
                temp.x++;
                temp.y--;

                if (temp.x > 7 || temp.y < 0)
                    break;

                moves[rowChecker][j] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            for (k = 0; k < 7; k++){
                temp.x--;
                temp.y--;

                if (temp.x < 0 || temp.y < 0)
                    break;

                moves[rowChecker][k] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            for (l = 0; l < 7; l++){
                temp.x--;
                temp.y++;

                if (temp.x < 0 || temp.y > 7)
                    break;

                moves[rowChecker][l] = temp;
            }
            break;

        case rook:
            for (i = 0; i < 7; i++){
                temp.x++;

                if (temp.x > 7)
                    break;

                moves[rowChecker][i] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;

            for (j = 0; j < 7; j++){
                temp.y--;

                if (temp.y < 0)
                    break;

                moves[rowChecker][j] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.y = p.y;

            for (k = 0; k < 7; k++){
                temp.x--;

                if (temp.x < 0)
                    break;

                moves[rowChecker][k] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;

            for (l = 0; l < 7; l++){
                temp.y++;

                if (temp.y > 7)
                    break;

                moves[rowChecker][l] = temp;
            }
            break;

        case queen:
            for (i = 0; i < 7; i++){
                temp.x++;
                temp.y++;

                if (temp.x > 7 || temp.y > 7)
                    break;

                moves[rowChecker][i] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            for (j = 0; j < 7; j++){
                temp.x++;
                temp.y--;

                if (temp.x > 7 || temp.y < 0)
                    break;

                moves[rowChecker][j] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            for (k = 0; k < 7; k++){
                temp.x--;
                temp.y--;

                if (temp.x < 0 || temp.y < 0)
                    break;

                moves[rowChecker][k] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            for (l = 0; l < 7; l++){
                temp.x--;
                temp.y++;

                if (temp.x < 0 || temp.y > 7)
                    break;

                moves[rowChecker][l] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            for (m = 0; m < 7; m++){
                temp.x++;

                if (temp.x > 7)
                    break;

                moves[rowChecker][m] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;

            for (n = 0; n < 7; n++){
                temp.y--;

                if (temp.y < 0)
                    break;

                moves[rowChecker][n] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.y = p.y;

            for (o = 0; o < 7; o++){
                temp.x--;

                if (temp.x < 0)
                    break;

                moves[rowChecker][o] = temp;
            }

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;

            for (q = 0; q < 7; q++){
                temp.y++;

                if (temp.y > 7)
                    break;

                moves[rowChecker][q] = temp;
            }
            break;

        case knight:
            temp.x += 2;
            temp.y++;

            if (temp.x <= 7 && temp.y <= 7)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;
            temp.x += 2;
            temp.y--;

            if (temp.x <= 7 && temp.y >= 0)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;
            temp.x++;
            temp.y -= 2;

            if (temp.x <= 7 && temp.y >= 0)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;
            temp.x--;
            temp.y -= 2;

            if (temp.x >= 0 && temp.y >= 0)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;
            temp.x -= 2;
            temp.y++;

            if (temp.x >= 0 && temp.y <= 7)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;
            temp.x -= 2;
            temp.y--;

            if (temp.x >= 0 && temp.y >= 0)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;
            temp.x--;
            temp.y += 2;

            if (temp.x >= 0 && temp.y <= 7)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;
            temp.x++;
            temp.y += 2;

            if (temp.x <= 7 && temp.y <= 7)
                moves[rowChecker][0] = temp;

            break;

        case king:
            temp.x++;
            if (temp.x <= 7)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;

            temp.x++;
            temp.y--;
            if (temp.x <= 7 && temp.y >= 0)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            temp.y--;
            if (temp.y >= 0)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.y = p.y;

            temp.x--;
            temp.y--;
            if (temp.x >= 0 && temp.y >= 0)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            temp.x--;
            if (temp.x >= 0)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;

            temp.x--;
            temp.y++;
            if (temp.x >= 0 && temp.y <= 7)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            temp.y++;
            if (temp.y <= 7)
                moves[rowChecker][0] = temp;

            if (moves[rowChecker][0].type != empty)
                rowChecker++;

            temp.x = p.x;
            temp.y = p.y;

            temp.x++;
            temp.y++;
            if (temp.x <= 7 && temp.y <= 7)
                moves[rowChecker][0] = temp;

            break;

        case empty:
            break;
    }

    return moves;
}