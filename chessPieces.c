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

    static Piece moves[27]; // 27 is the largest possible number of moves a piece could make
    Piece temp = { p.isWhite, p.type, p.x, p.y };

    switch (p.type) {

        case pawn:
            if (p.isWhite && p.y == 6) {
                temp.y -= 2;
                moves[1] = temp;
                temp.y = p.y;
            } if (p.isWhite) {
                temp.y--;
                moves[0] = temp;
            }

            if (!(p.isWhite) && p.y == 1) {
                temp.y += 2;
                moves[1] = temp;
                temp.y = p.y;
            } if (!(p.isWhite)) {
                temp.y++;
                moves[0] = temp;
            }
            break;

        case bishop:
            for (i = 0; i < 7; i++){
                temp.x++;
                temp.y++;

                if (temp.x > 7 || temp.y > 7)
                    break;

                moves[i] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (j = i; j < i + 7; j++){
                temp.x++;
                temp.y--;

                if (temp.x > 7 || temp.y < 0)
                    break;

                moves[j] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (k = j; k < j + 7; k++){
                temp.x--;
                temp.y--;

                if (temp.x < 0 || temp.y < 0)
                    break;

                moves[k] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (l = k; l < k + 7; l++){
                temp.x--;
                temp.y++;

                if (temp.x < 0 || temp.y > 7)
                    break;

                moves[l] = temp;
            }
            break;

        case rook:
            for (i = 0; i < 7; i++){
                temp.x++;

                if (temp.x > 7)
                    break;

                moves[i] = temp;
            }

            temp.x = p.x;

            for (j = i; j < i + 7; j++){
                temp.y--;

                if (temp.y < 0)
                    break;

                moves[j] = temp;
            }

            temp.y = p.y;

            for (k = j; k < j + 7; k++){
                temp.x--;

                if (temp.x < 0)
                    break;

                moves[k] = temp;
            }

            temp.x = p.x;

            for (l = k; l < k + 7; l++){
                temp.y++;

                if (temp.y > 7)
                    break;

                moves[l] = temp;
            }
            break;

        case queen:
            for (i = 0; i < 7; i++){
                temp.x++;
                temp.y++;

                if (temp.x > 7 || temp.y > 7)
                    break;

                moves[i] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (j = i; j < i + 7; j++){
                temp.x++;
                temp.y--;

                if (temp.x > 7 || temp.y < 0)
                    break;

                moves[j] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (k = j; k < j + 7; k++){
                temp.x--;
                temp.y--;

                if (temp.x < 0 || temp.y < 0)
                    break;

                moves[k] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (l = k; l < k + 7; l++){
                temp.x--;
                temp.y++;

                if (temp.x < 0 || temp.y > 7)
                    break;

                moves[l] = temp;
            }

            temp.x = p.x;
            temp.y = p.y;

            for (m = l; m < l + 7; m++){
                temp.x++;

                if (temp.x > 7)
                    break;

                moves[m] = temp;
            }

            temp.x = p.x;

            for (n = m; n < m + 7; n++){
                temp.y--;

                if (temp.y < 0)
                    break;

                moves[n] = temp;
            }

            temp.y = p.y;

            for (o = n; o < n + 7; o++){
                temp.x--;

                if (temp.x < 0)
                    break;

                moves[o] = temp;
            }

            temp.x = p.x;

            for (q = o; q < o + 7; q++){
                temp.y++;

                if (temp.y > 7)
                    break;

                moves[q] = temp;
            }
            break;

        case knight:
            temp.x += 2;
            temp.y++;

            if (temp.x <= 7 && temp.y <= 7)
                moves[0] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x += 2;
            temp.y--;

            if (temp.x <= 7 && temp.y >= 0)
                moves[1] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x++;
            temp.y -= 2;

            if (temp.x <= 7 && temp.y >= 0)
                moves[2] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x--;
            temp.y -= 2;

            if (temp.x >= 0 && temp.y >= 0)
                moves[3] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x -= 2;
            temp.y++;

            if (temp.x >= 0 && temp.y <= 7)
                moves[4] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x -= 2;
            temp.y--;

            if (temp.x >= 0 && temp.y >= 0)
                moves[5] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x--;
            temp.y += 2;

            if (temp.x >= 0 && temp.y <= 7)
                moves[6] = temp;

            temp.x = p.x;
            temp.y = p.y;
            temp.x++;
            temp.y += 2;

            if (temp.x <= 7 && temp.y <= 7)
                moves[7] = temp;

            break;

        case king:
            temp.x++;
            if (temp.x <= 7)
                moves[0] = temp;

            temp.x = p.x;

            temp.x++;
            temp.y--;
            if (temp.x <= 7 && temp.y >= 0)
                moves[1] = temp;

            temp.x = p.x;
            temp.y = p.y;

            temp.y--;
            if (temp.y >= 0)
                moves[2] = temp;

            temp.y = p.y;

            temp.x--;
            temp.y--;
            if (temp.x >= 0 && temp.y >= 0)
                moves[3] = temp;

            temp.x = p.x;
            temp.y = p.y;

            temp.x--;
            if (temp.x >= 0)
                moves[4] = temp;

            temp.x = p.x;

            temp.x--;
            temp.y++;
            if (temp.x >= 0 && temp.y <= 7)
                moves[5] = temp;

            temp.x = p.x;
            temp.y = p.y;

            temp.y++;
            if (temp.y <= 7)
                moves[6] = temp;

            temp.x = p.x;
            temp.y = p.y;

            temp.x++;
            temp.y++;
            if (temp.x <= 7 && temp.y <= 7)
                moves[7] = temp;

            break;
    }

    return moves;
}