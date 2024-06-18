#ifndef queue_linkedlist
#define queue_linkedlist
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
} Node, *NodePtr;

typedef struct{
    NodePtr front;
    NodePtr rear;
} Queue;

void initQueue(Queue* q);
bool isEmpty(Queue q);
bool enqueue(Queue* q, int elem);
bool dequeue(Queue* q);
int front(Queue q);
int rear(Queue q);
void display(Queue q);

#endif