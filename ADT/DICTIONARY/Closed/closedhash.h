#ifndef CLOSE_HASH
#define CLOSE_HASH

#include <stdbool.h>

#define DELETED_NODE ((Info*) -1)

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
    int size;
} Hash_List;

void initTable(Hash_List *H, int size);
unsigned int hashString(const char *data);
int hash(Info person, int size);
int search(Hash_List*H, int key);
void resizeArray(Hash_List *H);

bool checkThreshold(Hash_List H); //65%
void printInfo(Info person);
void display(Hash_List H);

void insertInfo(Hash_List *H, Info newPerson);
void deleteInfo(Hash_List *H, Info target);

#endif