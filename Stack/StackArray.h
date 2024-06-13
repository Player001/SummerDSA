#ifndef STACK_ARRAY
#define STACK_ARRAY

#include<stdbool.h>
#define MAX 20

typedef struct {
	int data[MAX];
	int top;
}StackArrayList;

bool isEmpty(StackArrayList s);
bool isFull(StackArrayList s);

void initStack(StackArrayList *s);
StackArrayList createStack();

bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList);

void display(StackArrayList s);
void visualize(StackArrayList s);

//others
//create a function that would get all even numbers and return as a
//new stack removing from the old stack

#endif