#include <stdio.h>
#include <stdlib.h>
#include "sets.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*Create a Program to find the Union and Intersection
	- 2 functions that accepts 2 sets and find Union & Intersection
	- Functions to add or delete values in the set
	- Keep the integrity of the 2 initial sets when finding the Union and Intersection
	- Display resulting Union and Intersection
	- Array Implementation*/
int main(int argc, char *argv[]) {
	SET A[]={1,2,3,4,5};
	SET B[]={4,5,6,7,8};
	int sizeA = sizeof(A)/sizeof(A[0]);
	int sizeB = sizeof(B)/sizeof(B[0]);
	UNION C;
	INTERSECTION D;
	int sizeC, sizeD;

	sizeC = getUnion(A, B, &C, sizeA, sizeB);
	sizeD = getIntersection(A, B, &D, sizeA, sizeB);

	printf("%d\n", sizeA);
	displayUnion(&C, sizeC);

	free(C);
	free(D);

	return 0;
}