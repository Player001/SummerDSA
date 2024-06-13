// #include <stdio.h>
// #include <stdlib.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList list;

	initStack(&list);
	
	stack_push(&list, 1);
	stack_push(&list, 2);
	stack_push(&list, 3);
	stack_push(&list, 4);
	display(list);
	stack_pop(&list);
	stack_push(&list, 5);
	visualize(list);

	return 0;
}