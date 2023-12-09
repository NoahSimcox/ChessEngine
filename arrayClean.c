#include "arrayClean.h"


Piece* arrayClean(Piece arr[27]){

    int count = 0;

    while (arr[count].type != empty){
        count++;
    }

    Piece newArr[count];

    for (int i = 0; i < count; i++){
        newArr[i] = arr[i];
    }

    return newArr;
}