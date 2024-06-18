#include <stdio.h>
#include <stdlib.h>
#include "QueueCircular.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue q;

	initQueue(&q);
	isEmpty(q);

	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	enqueue(&q,5);
	enqueue(&q,6);
	isFull(q);
	printf("Front: %d\n", front(q));
	printf("Rear: %d\n", rear(q));
	display(q);
	
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	printf("Front: %d\n", front(q));
	printf("Rear: %d\n", rear(q));
	display(q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	isEmpty(q);
	display(q);

	return 0;
}