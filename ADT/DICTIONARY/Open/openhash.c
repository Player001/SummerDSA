#include "openhash.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Hash Functions
int getKey(char data[]){
    int key = (int)strlen(data);
    return key;
}

int hash(Info person, int size){
    int hashKey, key1, key2, i;
    key1 = getKey((&person)->name.Fname);
    key2 = getKey((&person)->address.City);

    hashKey = (key1 + key2) % size; 

    return hashKey;
}

// Utility Functions
bool checkTreshold(Hash_List H, int size){
    bool r = false;
    float val = static_cast<float>(H.count)/size;

    return r;
}