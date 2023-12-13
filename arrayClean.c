#include "arrayClean.h"
#include "stdlib.h"


Piece* arrayClean(Piece arr[27], int* count){

    int size = 0;

    while (arr[size].type != empty){
        size++;
    }

    Piece* newArr = malloc(size * sizeof(Piece));
    if (newArr == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    for (int i = 0; i < size; i++){
        newArr[i] = arr[i];
    }

    *count = size;

    return newArr;
}