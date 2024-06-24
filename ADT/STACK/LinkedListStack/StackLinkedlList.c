#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkedList.h"

bool isEmpty(StackLinkedList s){
    return s.top == NULL;
}

void initStack(StackLinkedList *s){
    s->top = NULL;
}

StackLinkedList createStack(){
    StackLinkedList s;
    initStack(&s);
    return s;
}

bool stack_push(StackLinkedList *s, int elem){
    bool r = false;
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    
    if (newNode == NULL){
        printf("\nMemory Allocation Failed");
    } else {
        newNode->data = elem;
        newNode->next = s->top;
        s->top = newNode;
        r = true;
    }

    return r;
}

bool stack_pop(StackLinkedList *s){
    bool r = false;
    NodePtr tmp;

    if(isEmpty(*s)){
        printf("\nList is Empty\n");
    } else {
        tmp = s->top;
        s->top = s->top->next;
        free(tmp);
        r = true;
    }

    return r;
}

int stack_peek(StackLinkedList s){
    int val;

    if(s.top == NULL){
        printf("\nList is Empty\n");
    } else {
        val = s.top->data;
    }

    return val;
}

void display(StackLinkedList s){
    StackLinkedList tmpStack = createStack();
    NodePtr current = s.top;

    while(current != NULL){
        stack_push(&tmpStack, current->data);
        current = current->next;
    }

    while(!isEmpty(tmpStack)){
        printf(" %d", stack_peek(tmpStack));
        stack_pop(&tmpStack);
    }
    printf("\n");
}

void visualize(StackLinkedList s){
    NodePtr current = s.top;
    
    printf("Top -> ");
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL \n");
}