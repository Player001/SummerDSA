#include<stdio.h>
#include <string.h>
// #include<string.h>

/*1. Insert
    -Insert Front/First
    -Insert Rear/End/Last
    -Insert at Index
    -Insert Sorted - By Age

  2.Delete
    -Front
    -At Index
    -Rear
*/

/*Structure*/
typedef struct  {
    char fname[20];
    char lname[20];
}studName;

typedef struct {
    int month;
    int year;
}Bday;

typedef struct {
    studName Name;
    Bday birthdate;
    int age;
    int idNum;
}studentInfo;

typedef struct {
    studentInfo studList[20];
    int studCount;
}classRecord;

/*Functions Prototypes*/

/*Utility functions*/
void opt();
void printList(classRecord);
void sortList(classRecord*); //By Age
studentInfo createStudent(studentInfo*);

/*Inserst Functions*/
void insertFirst(classRecord*);
void insertLast(classRecord*);
void insertIndex(classRecord*, studentInfo ,int);
void insertSorted(classRecord*);

/*Delete Functions*/
void deleteFront(classRecord*);
void deleteLast(classRecord*);
void deleteIndex(classRecord*, int);

int main(){
    classRecord list = {.studCount = 0};
    studentInfo student;
    int selection=-1;
    int c;

    student.age = -1;
    while(selection != 0){
        
        opt();
        scanf("%d", &selection);
        
        if(selection == 1){
            printList(list);
        }
        else if (selection == 2) {
            printf("\nInserting First");
            insertFirst(&list);
        }
        else if (selection == 3) {
            printf("\nInserting Last");
            insertLast(&list);
        } 
        else if (selection == 4) {
            printf("\nPlease enter which index to insert to[0-19]: ");
            scanf(" %d", &c);
            insertIndex(&list, student,c);
        }
        else if (selection == 5) {
            printf("\nSorting List");
            sortList(&list);
            insertSorted(&list);
        }
        else if (selection == 6) {
            printf("\nDeleting Front");
            deleteFront(&list);
        }
        else if (selection == 7) {
            printf("\nDeleting Last");
            deleteLast(&list);
        }
        else if (selection == 8) {
            printf("\nSelect index to delete [0-19]: ");
            scanf(" %d", &c);
            deleteIndex(&list, c);
        }
        else if (selection == 9) {
            sortList(&list);
        }
        else if(selection == 0){
            printf("\nGoodbye.");
            selection = 0;
        }
        else {
            printf("\nUnkown Selection.");
            selection = -1;
        }
    }

    return 0;
}

void opt(){
    printf("\n=================================================================");
    printf("\nOptions:");
    printf("\n1 Print Current List");
    printf("\n2 Insert First");
    printf("\n3 Insert Last");
    printf("\n4 Insert at Index");
    printf("\n5 Insert Sorted");
    printf("\n6 Delete Front");
    printf("\n7 Delete Last");
    printf("\n8 Delete Index");
    printf("\n9 Sort List");
    printf("\n0 Quit");
    printf("\nSelect a function by inputting a number: ");
}

void printList(classRecord list){
    int ndx;
    
    if(list.studCount == 0){
        printf("\nList is empty");
    } else {
        for(ndx = 0 ; ndx < list.studCount ; ndx++){
            printf("\n==================================================");
            printf("\nName: %s %s", list.studList[ndx].Name.fname, list.studList[ndx].Name.lname);
            printf("\nAge: %d", list.studList[ndx].age);
            printf("\nBirthdate: %d %d",list.studList[ndx].birthdate.month, list.studList[ndx].birthdate.year );
            printf("\nId Number: %d",list.studList[ndx].idNum);
        }
    }
}

void sortList(classRecord *list){
    int ndx,jdx;
    studentInfo tmp;

    if(list->studCount == 0){
        printf("List is empty");
    } else {
        for(ndx = 0 ; ndx < list->studCount-1 ; ndx++){
            for(jdx = 0 ; jdx < list->studCount-ndx-1 ; jdx++){
                if(list->studList[jdx].age > list->studList[jdx+1].age){
                    tmp = list->studList[jdx];
                    list->studList[jdx] = list->studList[jdx+1];
                    list->studList[jdx+1] = tmp;
                }
            }
        }
    }
}

studentInfo createStudent(studentInfo *student){
    
    printf("\nInput First name: ");
    scanf(" %20[^\n]", student->Name.fname);

    printf("\nInput Last name: ");
    scanf(" %20[^\n]", student->Name.lname);

    printf("\nInput Month of Birth in numbers: ");
    scanf(" %d", &student->birthdate.month);

    printf("\nInput Year of Birth: ");
    scanf(" %d", &student->birthdate.year);

    printf("\nInput Age: ");
    scanf(" %d", &student->age);

    printf("\nInput Id Number: ");
    scanf(" %d", &student->idNum);

    return *student;
}

void insertFirst(classRecord *list){
    studentInfo student;
    student = createStudent(&student);
    int ndx;

    if (list->studCount >= 20){
        printf("\nList is Full!");
    } else if(list->studCount == 0){
        list->studList[0] = student;
        list->studCount++;
    } else {
        for(ndx = list->studCount ; ndx > 0; ndx--){
            list->studList[ndx] = list->studList[ndx-1];
        }
        list->studList[0] = student;
        list->studCount++;
    }
}

void insertLast(classRecord *list){
    studentInfo student;
    student = createStudent(&student);

    if (list->studCount >= 20){
        printf("\nList is Full!");
    } else if(list->studCount == 0){
        list->studList[0] = student;
        list->studCount++;
    } else {
        list->studList[list->studCount] = student;
        list->studCount++;
    }
}

void insertIndex(classRecord *list, studentInfo student, int c){
    int ndx;

    if (c > list->studCount || c < 0){
        printf("\nInvalid index");
    } else {
        if(student.age == -1){
            student = createStudent(&student);
        }
        for(ndx = list->studCount ; ndx > c; ndx--){
            list->studList[ndx] = list->studList[ndx-1];
        }
        list->studList[c] = student;
        list->studCount++;
    }
}

void insertSorted(classRecord *list){
    studentInfo student;
    int ndx;

    if(list->studCount >= 20){
        printf("List is Full!");
    } else {
        student = createStudent(&student);
        for (ndx = 0; ndx < list->studCount && list->studList[ndx].age <= student.age; ndx++) {}
        insertIndex(&(*list), student, ndx);
    }
}

void deleteFront(classRecord *list){
    int ndx;

    if(list->studCount == 0){
        printf("List is Empty!");
    } else {
        for(ndx = 0 ; ndx < list->studCount ; ndx++){
            list->studList[ndx] = list->studList[ndx+1];
        }
        list->studCount--;
    }
}

void deleteLast(classRecord *list){
    if(list->studCount == 0){
        printf("List is Empty!");
    }
    else {
        list->studCount--;
    }
}

void deleteIndex(classRecord *list, int elem){
    int ndx;

    if(list->studCount == 0){
        printf("List is Empty!");
    }
    else if (elem > list->studCount || elem < 0) {
        printf("That index is out of bounds");
    } else {
        for(ndx = elem ; ndx < list->studCount ; ndx++){
            list->studList[ndx] = list->studList[ndx+1];
        }
        list->studCount--;
    }
}