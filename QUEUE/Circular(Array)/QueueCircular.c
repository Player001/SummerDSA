#include <stdio.h>
#include <stdbool.h>
#include "QueueCircular.h"

void initQueue(Queue *q){
    int ndx; 

    for(ndx = 0; ndx < MAX ; ndx++){
        q->data[ndx] = -1;
    }

    q->rear = 0;
    q->front = 1;
}

bool isEmpty(Queue q){
    bool r = false;
   
    if((q.rear + 1) % MAX == q.front){
        r = true;
    }

    return r;
}

bool isFull(Queue q){
    bool r = false;

    if((q.rear + 2) % MAX == q.front){
        r = true;
    }

    return r;
}

bool enqueue(Queue *q, int elem){
    bool r = false;

    if(isFull(*q)){
        printf("\nQueue is Full!\n");
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = elem;
    }

    return r;
}

bool dequeue(Queue *q) {
    bool r = false;

    if(isEmpty(*q)){
        printf("\nQueue is Empty\n");
    } else {
        q->data[q->front] = -1;
        q->front = (q->front + 1) % MAX;
    }

    return r;
}

int front(Queue q){
    int val;

    if(isEmpty(q)){
        printf("Queue is Empty\n");
    } else {
        val = q.data[q.front];
    }

    return val;
}

int rear(Queue q){
    int val;

    if(isEmpty(q)){
        printf("Queue is Empty\n");
    } else {
        val = q.data[q.rear];
    }

    return val;
}

void display(Queue q){
    int ndx;
    if(isEmpty(q)){
        printf("Queue is empty!\n");
    } else {
        for(ndx = q.front ; isEmpty(q) != true ; dequeue(&q)){
            printf("%d\n", front(q));
        }
    }
}