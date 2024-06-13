#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

bool isEmpty(StackArrayList s){
	return s.top == -1 ? true : false;
}

bool isFull(StackArrayList s){
	
	return s.top == MAX-1 ? true : false;
}

void initStack(StackArrayList *s){
	s->top = 0;
}

StackArrayList createStack(){
	StackArrayList newStack;
	initStack(&newStack);
	return newStack;
}

bool stack_push(StackArrayList *s, int elem){
	bool r;
	
	if(isFull(*s)==1){
		printf("Stack is Full");
	} else {
		s->data[s->top] = elem;
		s->top++;
	}
	
	r = isEmpty(*s);
	
	return r;
}

bool stack_pop(StackArrayList *s){
	bool r;
	
	if(isEmpty(*s)==1){
		printf("Stack is Empty");
	} else {
		s->	top--;
	}
	
	return r;
}
