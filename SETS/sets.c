#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "sets.h"

bool existsInSet(int elem, SET A[], int size){
    int ndx;
    bool r = false;

    for(ndx = 0 ; ndx < size ; ndx++){
        if(A[ndx] == elem){
            r = true;
        }
    }

    return r;
}

// Find and Create Union & Intersection
SET getUnion(SET A[], SET B[], UNION *C, int sizeA, int sizeB){
    int ndx;
    int sizeC = 0;
    *C = (int*)malloc((sizeA + sizeB) * sizeof(int));

    // Add elements from A to C
    for(ndx = 0 ; ndx < sizeA ; ndx++){
        if(!existsInSet(A[ndx], *C, sizeC)){
            (*C)[sizeC++] = A[ndx];
        }
    }

    // Add elements from B to C
    for(ndx = 0 ; ndx < sizeB ; ndx++){
        if(!existsInSet(B[ndx], *C, sizeC)){
            (*C)[sizeC++] = B[ndx];
        }
    }

    return sizeC;
}

SET getIntersection(SET A[], SET B[], INTERSECTION *C, int sizeA, int sizeB){
    int ndx;
    int sizeC = 0;
    *C = (int*)malloc((sizeA + sizeB) * sizeof(int));

    for(ndx = 0 ; ndx < sizeA ; ndx++){
        // if elem in A exists in B
        if(existsInSet(A[ndx], B, sizeB)){
            // if it does not exist in C
            if(!existsInSet(A[ndx], *C, sizeC)){
                (*C)[sizeC++] = A[ndx];
            }
        }
    }

    return sizeC;
}

// Display
void displayUnion(SET A[], int size){
    int ndx;

    for(ndx = 0 ; ndx < size ; ndx++){
        printf("%d -> ", A[ndx]);
    }
}