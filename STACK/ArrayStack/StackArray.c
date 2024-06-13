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
	bool r = isFull(*s);
	
	if(r == 1){
		printf("Stack is Full");
	} else {
		s->data[s->top] = elem;
		s->top++;
	}
	
	return r;
}

bool stack_pop(StackArrayList *s){
	bool r = isEmpty(*s);
	
	if(r == 1){
		printf("Stack is Empty");
	} else {
		printf("%d",s->data[s->top]);
		s->	top--;
	}
	
	return r;
}

int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void display(StackArrayList s){
	int val;
	StackArrayList tmp = createStack();
	
	printf("\nStack from top to bottom:\n");
	while(!isEmpty(s)){
		val = stack_peek(s);
		printf(" %d\n", val);
		stack_pop(&s);
		stack_push(&tmp, val);
	}
	
	while(!isEmpty(tmp)){
		stack_push(&s, stack_peek(tmp));
		stack_pop(&tmp);
	}
}

void visualize(StackArrayList s){
	int ndx;

	printf("\nVisualizing Stack from top to bottom:\n");
	
}