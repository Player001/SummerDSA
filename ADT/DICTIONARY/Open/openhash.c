#include "openhash.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Hash Functions
int getKey(char data[]) {
    return (int)strlen(data);
}

int hash(Info person, int size) {
    int key1 = getKey(person.name.Fname);
    int key2 = getKey(person.address.City);
    return (key1 + key2) % size;
}

// Utility Functions
bool checkThreshold(Hash_List H) {
    double val;
    val = (double)H.count / H.size;
    printf("%.2f", val);
    return val >= 0.65;
}

void initTable(Hash_List *H, int size) {
    int n;
    H->count = 0;
    H->size = size;
    H->list = (InfoPtr *)malloc((size_t)size * sizeof(InfoPtr));
    for (n = 0; n < size; n++) {
        H->list[n] = NULL;
    }
}

void printInfo(InfoPtr person) {
    printf("\nName: %s %s", person->name.Fname, person->name.Lname);
    printf("\nAddress: %s, %s, %s", person->address.Road, person->address.Barangay, person->address.City);
}

void display(Hash_List H) {
    int n;
    InfoPtr list;
    if (H.count == 0) {
        printf("\nThe table is empty");
    } else {
        for (n = 0; n < H.size; n++) {
            list = H.list[n];
            while (list != NULL) {
                printInfo(list);
                list = list->next;
            }
        }
    }
}

// Table Functions
void insertSorted(InfoPtr *list, InfoPtr newPerson) {
    InfoPtr curr;
    if (*list == NULL || strcmp(newPerson->name.Fname, (*list)->name.Fname) < 0) {
        newPerson->next = *list;
        *list = newPerson;
    } else {
        curr = *list;
        while (curr->next != NULL && strcmp(newPerson->name.Fname, curr->next->name.Fname) < 0) {
            curr = curr->next;
        }
        newPerson->next = curr->next;
        curr->next = newPerson;
    }
}

void resizeArray(Hash_List *H) {
    int newSize = H->size * 2;
    InfoPtr *newList = (InfoPtr *)malloc((size_t)newSize * sizeof(InfoPtr));
    InfoPtr curr, next;

    for (int n = 0; n < newSize; n++) {
        newList[n] = NULL;
    }

    for (int n = 0; n < H->size; n++) {
        curr = H->list[n];
        while (curr != NULL) {
            next = curr->next;
            int newIndex = hash(*curr, newSize);
            curr->next = NULL;
            insertSorted(&newList[newIndex], curr);
            curr = next;
        }
    }

    free(H->list);
    H->list = newList;
    H->size = newSize;
}

void insertInfo(Hash_List *H, Info person) {
    int ndx = hash(person, H->size);
    InfoPtr newPerson = (InfoPtr)malloc(sizeof(Info));
    *newPerson = person;
    newPerson->next = NULL;

    insertSorted(&(H->list[ndx]), newPerson);
    H->count++;

    if (checkThreshold(*H)) {
        resizeArray(H);
    }
}

void deleteInfo(Hash_List *H, Info person) {
    int ndx = hash(person, H->size);
    InfoPtr curr = H->list[ndx];
    InfoPtr prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->name.Fname, person.name.Fname) == 0 && strcmp(curr->name.Lname, person.name.Lname) == 0) {
            if (prev == NULL) {
                H->list[ndx] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            H->count--;
            curr = NULL;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}
