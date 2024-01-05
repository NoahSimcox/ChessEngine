#include "evaluate.h"
#include "chessPieces.h"

float calculate_points(Piece currPieces[32]){

    float totalPoints = 0;

    for(int i = 0; i < 32; i++){

        totalPoints += currPieces[i].value;
    }

    return totalPoints;
}