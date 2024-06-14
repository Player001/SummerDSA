#include "QueueLinear.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue *q){
    return (q->front == NULL) ? true : false;
}

bool enqueue(Queue *q, int elem){
    bool r = false;
    NodePtr tmp = malloc(sizeof(Node));

    if(isEmpty(q)){
        tmp->data = elem;
        tmp->next = NULL;
        q->front = tmp; 
        q->rear = tmp;
        r = true;
    } else{
        q->rear->next = &(*tmp);
        tmp->next = q->rear;
    }

    return r;
}

bool dequeue(Queue *q){
    bool r = false;
    NodePtr tmp;

    if(isEmpty(q)){
        printf("\nQueue is empty!");
    } else {
        tmp = q->front;
        q->front = q->front->next;
        free(tmp);
        r = true;
    }
    
    return r;
}

void display(Queue q){
    NodePtr tmp;

    for(tmp = q.front ; tmp != NULL ; tmp = tmp->next){
        printf("\n%d", tmp->data);

    }   
}