#ifndef STACK_LL
#define STACK_LL

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
}Node, *NodePtr;

typedef struct {
    NodePtr top;
} StackLinkedList;

bool isEmpty(StackLinkedList s);
void initStack(StackLinkedList *s);

StackLinkedList createStack();

bool stack_push(StackLinkedList *s, int elem);
bool stack_pop(StackLinkedList *s);
int stack_peek(StackLinkedList s);

void display(StackLinkedList s);
void visualize(StackLinkedList s);

#endif