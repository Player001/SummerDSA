#ifndef CLOSE_HASH
#define CLOSE_HASH

#include <stdbool.h>

typedef struct{ 
 char Fname[20];
 char Lname[20];
 } Cname;

typedef struct {
    char Road[20];
    char Barangay[20];
    char City[20];
} Address;

typedef struct {
    Cname name;
    Address address;
    bool deleted;
} Info;

typedef struct {
    Info *list;
    int count;
    int table_size;
} Hash_List;

void initialize(Hash_List *H, int size);
bool checkThreshold(Hash_List H); //load factor: 65%
unsigned int hashString(const char *data);
unsigned int hash(Info person, int increment, int table_size);
void resize(Hash_List *H);// if checkThreshold is true then resize

unsigned int search(Hash_List H, Info target); //will return the index / key to get the Info
void insertInfo(Hash_List *H, Info newPerson); //will insert info
void deleteInfo(Hash_List *H, Info target); //will use search to delete info
void findPerson(Hash_List H, Info person); //finds the person and prints

void printInfo(Info person);
void display(Hash_List H);
#endif