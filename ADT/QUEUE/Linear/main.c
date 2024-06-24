#include <stdio.h>
#include <stdlib.h>
#include "QueueLinear.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue q;

	initQueue(&q);
	
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	display(q);
	printf("Front: %d\n", front(q));
	printf("Rear: %d\n", rear(q));
	
	dequeue(&q);
	dequeue(&q);
	display(q);
	printf("Front: %d\n", front(q));
	printf("Rear: %d\n", rear(q));
	
	dequeue(&q);
	dequeue(&q);
	display(q);
	printf("Front: %d\n", front(q));
	printf("Rear: %d\n", rear(q));
	
	
	printf("%d\n", isEmpty(q));

	return 0;
}