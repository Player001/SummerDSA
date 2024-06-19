#include "QueueLinear.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue q){
	bool r = false;
	
	if(q.front == NULL){
		r = true;
	}
	
	return r;
}

bool enqueue(Queue *q, int elem){
    bool r = false;
    NodePtr tmp = (NodePtr)malloc(sizeof(Node));
    
    if(tmp == NULL){
    	printf("Memory Allocation failed!");
    } else {
    		tmp->data = elem;
	    	tmp->next = NULL;
	    if(isEmpty(*q) == true){
	    	q->front = tmp;
	    	q->rear = tmp;
	    	r = true;
		} else {
			q->	rear->next = tmp;
			q->rear = q->rear->next;	
			r = true;
		}
	}
    return r;
}

bool dequeue(Queue *q){
    bool r = false;
    NodePtr tmp;

    if(isEmpty(*q)){
        printf("Queue is empty!\n");
    } else {
		tmp = q->front;
		q->front = q->front->next;
		free(tmp);
		
		if(q->front == NULL){
    	q->rear = NULL;
		}
	}
		
    return r;
}

int front(Queue q){
	int val;
	
	if(isEmpty(q) == true) {
		val = -1;
	} else {
		val = q.front->data;
	}
	
	return val;
}

int rear(Queue q){
    int val;
	
	if(isEmpty(q) == true) {
		val = -1;
	} else {
		val = q.rear->data;
	}
	
	return val;
}

void display(Queue q){
	NodePtr tmp = q.front;
	
	if(isEmpty(q) == true) {
		printf("Queue is empty\n");
	} else {
		while (tmp != NULL) {
            printf("%d -> ", tmp->data);
            tmp = tmp->next;
        }
		printf("NULL\n");
	}
}