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

typedef struct {
    Cname name;
    Address address;
} Info, *InfoPtr;

typedef struct {
    InfoPtr list[6];
    int count;
} Hash_List;

// hash functions
int getKey(char *data);
int hash(Info person, int size);

// table functions
void resizeArray(Hash_List H, int *size);
void insertSorted(Hash_List H, Info person);
void addPerson(Hash_List H, Info person);
void deletePerson(Hash_List H, Info person);

// utility functions
bool checkTreshold(Hash_List H, int size); // check if # of elem >= 65% the size of the array
void initHash(Hash_List H); //set the count to 0
void printInfo(Info person); //prints the Info of a person
void display(Hash_List H); //prints the entire hash table

#endif