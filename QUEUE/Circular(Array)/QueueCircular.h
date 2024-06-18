#ifndef QUEUE_CIRCULAR
#define QUEUE_CIRCULAR

#include <stdbool.h>

#define MAX 7

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue  (Queue *q);
bool isEmpty    (Queue q);
bool isFull     (Queue q);
bool enqueue    (Queue* q, int elem);
bool dequeue    (Queue* q);
int front       (Queue q);
int rear        (Queue q);
void display    (Queue q);

#endif