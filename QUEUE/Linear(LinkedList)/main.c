#include <stdio.h>
#include <stdlib.h>
#include "QueueLinear.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue q;

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	display(q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);

	return 0;
}