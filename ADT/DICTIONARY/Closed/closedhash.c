#include "closedhash.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void initialize(Hash_List *H, int size){
    int x;
    H->table_size = size;
    H->count = 0;
    H->list = malloc((size_t)size * sizeof(Info));
    for(x = 0 ; x < size ; x++){
        H->list[x].name.Fname[0] = '\0'; //'\0' = empty;
        H->list[x].deleted = false;
    }
}

bool checkThreshold(Hash_List H){
    bool retVal = false;
    double loadFactor = (double)H.count / H.table_size;
    printf("\nLoad Factor: %.2f", loadFactor);
    if(loadFactor >= 0.65){
        retVal = true;
    }
    return retVal;
}

unsigned int hashString(const char *data){
    unsigned int hash = 0;
    while(*data){
        hash = (hash * 31) + (unsigned char)*data++;
    }
    return hash;
}

unsigned int hash(Info person, int increment,int table_size){
    unsigned int key1, key2, ndx;
    
    key1 = hashString(person.name.Fname);
    key2 = hashString(person.address.City);
    ndx = (key1 + (unsigned int)increment * key2) % (unsigned int)table_size;
    return  ndx;
}

// realloc vs malloc?
void resize(Hash_List *H){
    int i;
    int newSize = H->table_size * 2;
    Info *newArray = malloc((size_t)newSize * sizeof(Info));
    
    printf("\nResizing");

    if(newArray == NULL){
        fprintf(stderr,"Memory Allocation Failed!");
        exit(EXIT_FAILURE);
    }

    Hash_List newHash;
    initialize(&newHash, newSize);

    for(i = 0 ; i < H->table_size; i++){
        if(H->list[i].name.Fname[0] != '\0' && H->list[i].deleted == false){
            // printf("Before: ");
            // printInfo(H->list[i]);
            insertInfo(&newHash, H->list[i]);
            // printf("After: ");
            // printInfo(H->list[i]);
        }
    }

    free(H->list);
    H->list = newHash.list;
    H->count = newHash.count;
    H->table_size = newHash.table_size;
}

unsigned int search(Hash_List H, Info target){
    unsigned int key;
    int i;

    for(i = 0 ; i < H.count ; i++){
        key = hash(target, i, H.table_size);
        if(
            strcmp(H.list[key].name.Fname, target.name.Fname) == 0 &&
            strcmp(H.list[key].name.Lname, target.name.Lname) == 0 &&
            strcmp(H.list[key].address.Barangay, target.address.Barangay) == 0 &&
            strcmp(H.list[key].address.City, target.address.City) == 0 &&
            strcmp(H.list[key].address.Road, target.address.Road) == 0
            )
        {
            i = H.count;
        }
    }
    return key;
}

void insertInfo(Hash_List *H, Info newPerson){
    int i;
    Hash_List H_Copy = *H;
    unsigned int check = search(H_Copy, newPerson);
    unsigned int key = hash(newPerson, 1, H->table_size);

    if(H->list[key].name.Fname[0] == '\0'){
            printf("\n--------------------------------");
            printf("\nCheck the value at Index: %d", check);
            printf("\nInserting at Index: %d", key);
            
            H->list[key] = newPerson;
            H->list[key].deleted = false;
            H->count++;
    } else {
        for(i = 1; i < H->table_size ; i++){
            key = hash(newPerson, i, H->table_size);
            printf("\n--------------------------------");
            printf("\nCheck the value at Index: %d", check);
            printf("\nTrying Index: %d", key);
            // Check if they exist
            if(strcmp(H->list[check].name.Fname, newPerson.name.Fname) == 0 &&
                strcmp(H->list[check].name.Lname, newPerson.name.Lname) == 0 &&
                strcmp(H->list[check].address.Barangay, newPerson.address.Barangay) == 0 &&
                strcmp(H->list[check].address.City, newPerson.address.City) == 0 &&
                strcmp(H->list[check].address.Road, newPerson.address.Road) == 0
                )
            {
                printf("Already Exists");
                break;
            } else if(strcmp(H->list[key].name.Fname, newPerson.name.Fname) == 0 &&
                strcmp(H->list[key].name.Lname, newPerson.name.Lname) == 0 &&
                strcmp(H->list[key].address.Barangay, newPerson.address.Barangay) == 0 &&
                strcmp(H->list[key].address.City, newPerson.address.City) == 0 &&
                strcmp(H->list[key].address.Road, newPerson.address.Road) == 0
                )
            {
                printf("Already Exists");
                break;
            } else if (H->list[key].name.Fname[0] == '\0' || H->list[key].deleted == true) {
                H->list[key] = newPerson;
                H->list[key].deleted = false;
                H->count++;
                break;
            } else {
                printf("\nCollision!");         
            }
        }
    }
    
    if(checkThreshold(*H)){
        resize(H);
    }
}

void deleteInfo(Hash_List *H, Info target){
    unsigned int key = search(*H, target);

    if(strcmp(H->list[key].name.Fname, target.name.Fname) == 0 &&
        strcmp(H->list[key].name.Lname, target.name.Lname) == 0 &&
        strcmp(H->list[key].address.Barangay, target.address.Barangay) == 0 &&
        strcmp(H->list[key].address.City, target.address.City) == 0 &&
        strcmp(H->list[key].address.Road, target.address.Road) == 0
        )
    {
        H->list[key].deleted = true;
    } else {
        printf("\nEntry not Found");
    }
}

void findPerson(Hash_List H, Info person){
    unsigned int key = search(H, person);

    if(strcmp(H.list[key].name.Fname, person.name.Fname) == 0 &&
        strcmp(H.list[key].name.Lname, person.name.Lname) == 0 &&
        strcmp(H.list[key].address.Barangay, person.address.Barangay) == 0 &&
        strcmp(H.list[key].address.City, person.address.City) == 0 &&
        strcmp(H.list[key].address.Road, person.address.Road) == 0
        )
    {
        printf("\nFound at Index: %d", key);
        printInfo(H.list[key]);
    }
}

void printInfo(Info person){
    printf("Name: %s %s", person.name.Fname, person.name.Lname);
    printf(" | Address: %s %s %s", person.address.Road, person.address.Barangay, person.address.City);
}

void display(Hash_List H){
    int i;

    for(i = 0 ; i < H.table_size ; i++){
        printf(" \n| Index %d ", i);
        if(H.list[i].name.Fname[0] == '\0'){
            printf(" | Empty");
        } else if (H.list[i].deleted == true) {
            printf(" | Deleted");
        } else {
            printInfo(H.list[i]);
        }
    }
}