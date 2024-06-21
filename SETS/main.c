#include <stdio.h>
#include <stdlib.h>
#include "sets.h"

int main(int argc, char *argv[]) {
	SET *A = (SET*)malloc(sizeof(SET));
	SET *B = (SET*)malloc(sizeof(SET));
	int sizeA = 0;
	int sizeB = 0;
	UNION C;
	INTERSECTION D;
	int sizeC, sizeD;

	insertElem(&A, &sizeA, 1);
	insertElem(&A, &sizeA, 2);
	insertElem(&A, &sizeA, 3);
	insertElem(&A, &sizeA, 4);
	insertElem(&A, &sizeA, 5);
	
	insertElem(&B, &sizeB, 4);
	insertElem(&B, &sizeB, 5);
	insertElem(&B, &sizeB, 6);
	insertElem(&B, &sizeB, 7);
	insertElem(&B, &sizeB, 8);

	sizeC = getUnion(A, B, &C, sizeA, sizeB);
	sizeD = getIntersection(A, B, &D, sizeA, sizeB);

	displayUnion(C, sizeC);
	displayIntersection(D, sizeD);	

	deleteElem(&A, &sizeA, 4);
	deleteElem(&A, &sizeA, 5);
	insertElem(&A, &sizeA, 9);
	insertElem(&A, &sizeA, 9);	

	sizeC = getUnion(A, B, &C, sizeA, sizeB);
	sizeD = getIntersection(A, B, &D, sizeA, sizeB);

	displayUnion(C, sizeC);
	displayIntersection(D, sizeD);	

	free(A);
	free(B);
	free(C);
	free(D);

	return 0;
}