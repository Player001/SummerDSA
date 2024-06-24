#ifndef SETS_ARRAY
#define SETS_ARRAY

#include <stdbool.h>

typedef int SET, *UNION, *INTERSECTION;

bool existsInSet(int elem, SET *A, int size);

SET getUnion(SET *A, SET *B, UNION *C, int sizeA, int sizeB);
SET getIntersection(SET *A, SET *B, INTERSECTION *C, int sizeA, int sizeB);

void insertElem(SET **A, int *size, int elem);
void deleteElem(SET **A, int *size, int elem);

void displayUnion(SET *A, int size);
void displayIntersection(SET *A, int size);

#endif