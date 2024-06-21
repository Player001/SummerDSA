#ifndef SETS_ARRAY
#define SETS_ARRAY

#include <stdbool.h>

typedef int SET, *UNION, *INTERSECTION;

//Check if element exists
bool existsInSet(int elem, SET *A, int size);

// Find and create union and intersection
SET getUnion(SET *A, SET *B, UNION *C, int sizeA, int sizeB);
SET getIntersection(SET *A, SET *B, INTERSECTION *C, int sizeA, int sizeB);

// Add/Delete values
void insertElem(SET *A, int size, int elem);
void deleteElem(SET *A, int size, int elem);

// Display
void displayUnion(SET *A, int size);
void displayIntersection(SET *A, int size);

#endif