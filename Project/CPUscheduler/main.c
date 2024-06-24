#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ProcessList P;

	initProcess(&P);
	addProcess(&P);
	display(P);

	return 0;
}