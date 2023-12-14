#include "arrayClean.h"
#include "stdlib.h"


Piece* arrayClean(Piece arr[27], int* count){

    int size = 0;

    for (int j = 0; j < 27; j++){
        if (arr[j].type != empty){
            size++;
        }
    }

    Piece* newArr = malloc(size * sizeof(Piece));
    if (newArr == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    int increment = 0;
    for (int i = 0; i < 27; i++){
        if (arr[i].type != empty) {
            newArr[increment] = arr[i];
            increment++;
        }
    }

    *count = size;

    return newArr;
}