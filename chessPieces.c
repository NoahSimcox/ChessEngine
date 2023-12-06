#include "chessPieces.h"

Piece* possible_moves(Piece p) { // given the board is empty

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
            for (int i = 0; i < 7; i++){
                temp.x = p.x + 1;
                temp.y = p.y + 1;

                if (temp.x >= 8 || temp.y >= 8)
                    break;

                moves[i] = temp;
            }
            for (int j = 8; j < 15; j++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x + 1;
                temp.y = p.y - 1;

                if (temp.x >= 8 || temp.y <= 1 )
                    break;

                moves[j] = temp;
            }
            for (int k = 16; k < 23; k++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x - 1;
                temp.y = p.y + 1;

                if (temp.x <= 1 || temp.y >= 8)
                    break;

                moves[k] = temp;
            }
            for (int l = 24; l < 31; l++){
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
            for (int i = 0; i < 7; i++){
                temp.x = p.x + 1;

                if (temp.x >= 8)
                    break;

                moves[i] = temp;
            }
            for (int j = 8; j < 15; j++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x + 1;
                temp.y = p.y - 1;

                if (temp.x >= 8 || temp.y <= 1 )
                    break;

                moves[j] = temp;
            }
            for (int k = 0; k < 7; k++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x - 1;
                temp.y = p.y + 1;

                if (temp.x <= 1 || temp.y >= 8)
                    break;

                moves[k] = temp;
            }
            for (int l = 0; l < 7; l++){
                temp.x = p.x;
                temp.y = p.y;
                temp.x = p.x - 1;
                temp.y = p.y - 1;

                if (temp.x <= 1 || temp.y <= 1)
                    break;

                moves[l] = temp;
            }

    }
};