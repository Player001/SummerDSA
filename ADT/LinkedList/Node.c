#include <complex.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
1. Insert Front
2. Insert Rear
3. Insert Index (2)
*/

typedef struct {
    char name[20];
    int idNum;
    int age;
}info;

typedef struct Node{
    info data;
    struct Node *next;
}Node, *NodePtr;

info createStud();
void getStudent(info);
void getList(NodePtr);
void freeList(NodePtr*);

void insertFirst(NodePtr*);
void insertLast(NodePtr*);

int main(){
    // info student;
    NodePtr head = NULL;

    // student = createStud();
    insertFirst(&head);
    insertFirst(&head);
    insertLast(&head);

    getList(head);

    freeList(&head);
    return 0;
}

info createStud(){
    info newStudent;

    printf("Input Name: ");
    scanf(" %19[^\n]",newStudent.name);
    // strcpy(newStudent.name, "Joshua");

    printf("\nInput Id Number: ");
    scanf("%d", &newStudent.idNum);
    // newStudent.idNum = 19104510;

    printf("\nInput Age: ");
    scanf("%d", &newStudent.age);
    // newStudent.age = 24;

    return newStudent;
}

void getStudent(info student){
    printf("\n======================================");
    printf("\nName: %s", student.name);
    printf("\nAge %d",student.age);
    printf("\nId Number: %d",student.idNum);
}

void getList(NodePtr list){
    NodePtr tmp;

    for(tmp = list ; tmp != NULL ; tmp = tmp->next){
        getStudent(tmp->data);
    }
}

void freeList(NodePtr *list){
    NodePtr tmp;
    while (*list != NULL) {
        tmp = (*list)->next;
        free(*list);
        *list = tmp;
    }
}

void insertFirst(NodePtr *list){
    NodePtr tmp = malloc(sizeof(Node));
    tmp->data = createStud();

    if(*list == NULL){
        tmp->next = NULL;
        (*list) = tmp;
    } else {
        tmp->next = *list;
        (*list) = tmp;
    }
}

void insertLast(NodePtr *list){
    NodePtr tmp = malloc(sizeof(Node));
    tmp->data = createStud();
    tmp->next = NULL;

    if(*list == NULL){
        *list = tmp;
    } else {
        while (*list != NULL) {
            list = &(*list)->next;
        }
        *list = tmp;
    }
}