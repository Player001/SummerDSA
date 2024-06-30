#ifndef OPEN_HASH
#define OPEN_HASH

#include <stdbool.h>

/*Open Hashing Function
    -If your elements >= 65% the size of your array, increase the size of
    the array.
    -Add and delete elements.
    -When adding, insert sorted.
    -Retrieve the person.
*/

typedef struct {
    char Fname[20];
    char Lname[20];
} Cname;

typedef struct {
    char Road[20];
    char Barangay[20];
    char City[20];
} Address;

typedef struct node {
    Cname name;
    Address address;
    struct node *next;
} Info, *InfoPtr;

typedef struct {
    InfoPtr *list;
    int count;
    int size;
} Hash_List;

// Hash Functions
unsigned int hashString(const char *string);
int hash(Info person, int size);

// Table Functions
void insertSorted(InfoPtr *list, InfoPtr newPerson);
void resizeArray(Hash_List *H);
void insertInfo(Hash_List *H, Info person);
void deleteInfo(Hash_List *H, Info person);

// Utility Functions
bool checkThreshold(Hash_List H);
void initTable(Hash_List *H, int size);
void printInfo(InfoPtr person);
void display(Hash_List H);

#endif