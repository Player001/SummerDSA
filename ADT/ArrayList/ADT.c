#include<stdio.h>
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
void insertIndex(classRecord*);
void insertSorted(classRecord*);

/*Delete Functions*/
void deleteFront();
void deleteLast();
void deleteIndex();

int main(){
    classRecord list = {.studCount = 0};
    int selection=-1;

    while(selection != 0){
        
        opt();
        scanf("%d", &selection);
        
        if(selection == 1){
            printList(list);
        }
        else if (selection == 2) {
            insertFirst(&list);
        }
        else if (selection == 3) {
            insertLast(&list);
        } 
        else if (selection == 4) {
            insertIndex(&list);
        }
        else if (selection == 5) {
            printf("\nSorting List");
            insertSorted(&list);
        }
        else if(selection == 0){
            printf("Goodbye.");
            selection = 0;
        }
        else {
            printf("Unkown Selection.");
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

    printf("\nInput Month of Birth: ");
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

void insertIndex(classRecord *list){
    studentInfo student;
    int c, ndx;

    printf("\nPlease enter the index to insert at: ");
    scanf(" %d", &c);

    if (c > list->studCount || c < 0){
        printf("\nInvalid index");
    } else {
        student = createStudent(&student);
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

    student = createStudent(&student);
    for (ndx = list->studCount-1; student.age >= list->studList[ndx].age && student.age <= list->studList[ndx-1].age; ndx--) {
    
    }
}