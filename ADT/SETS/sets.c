#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "sets.h"

bool existsInSet(int elem, SET A[], int size){
    int ndx;
    bool r = false;

    for(ndx = 0 ; ndx < size && A[ndx] != elem; ndx++){}
    if(A[ndx] == elem){
        r = true;
    }

    return r;
}

SET getUnion(SET A[], SET B[], UNION *C, int sizeA, int sizeB){
    int ndx;
    int sizeC = 0;
    *C = (int*)malloc((size_t)(sizeA + sizeB) * sizeof(int));

    for(ndx = 0 ; ndx < sizeA ; ndx++){
        insertElem(C, &sizeC, A[ndx]);
    }

    for(ndx = 0 ; ndx < sizeB ; ndx++){
        insertElem(C, &sizeC, B[ndx]);
    }

    return sizeC;
}

SET getIntersection(SET A[], SET B[], INTERSECTION *C, int sizeA, int sizeB){
    int ndx;
    int sizeC = 0;
    *C = (int*)malloc((size_t)(sizeA + sizeB) * sizeof(int));

    for(ndx = 0 ; ndx < sizeA ; ndx++){
        if(existsInSet(A[ndx], B, sizeB)){
            insertElem(C, &sizeC, A[ndx]);
        }
    }

    return sizeC;
}

void insertElem(SET **A, int *size, int elem){
    if(!existsInSet(elem, *A, *size)){
        *A = (SET*)realloc(*A, (size_t)(*size + 1) * sizeof(SET));
        (*A)[*size] = elem;
        (*size)++;
    }
}
void deleteElem(SET **A, int *size, int elem){
    int ndx, jdx;
    
    for(ndx = 0 ; ndx < *size && (*A)[ndx] != elem ; ndx++){}

    if(ndx < *size) {
        for(jdx = ndx ; ndx < *size - 1 ; ndx++){
            (*A)[jdx] = (*A)[jdx + 1];
        }
        *A = (SET*)realloc(*A, (size_t)(*size - 1) * sizeof(SET));
        (*size)--;
    }
}

void displayUnion(SET A[], int size){
    int ndx;

    printf("\nUnion Set: |");
    for(ndx = 0 ; ndx < size ; ndx++){
        printf("%d|", A[ndx]);
    }
}

void displayIntersection(SET A[], int size){
    int ndx;

    printf("\nIntersection Set: |");
    for(ndx = 0 ; ndx < size ; ndx++){
        printf("%d|", A[ndx]);
    }
}