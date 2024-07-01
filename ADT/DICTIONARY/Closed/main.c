#include <stdio.h>
#include "closedhash.h"

int main(int argc, char *argv[]) {
    Hash_List hashTable;
    initialize(&hashTable, 7); // Initialize hash table with size 7

    // Example data to insert
    Info person1 = {{"John", "Doe"}, {"Main St", "Downtown", "City1"}, false};
    Info person2 = {{"Jane", "Smith"}, {"Broadway Ave", "Suburb", "City2"}, false};
    Info person3 = {{"Michael", "Brown"}, {"Park Rd", "Village", "City3"}, false};
    Info person4 = {{"Emily", "Johnson"}, {"Lake Ave", "Rural", "City4"}, false};
    Info person5 = {{"David", "Lee"}, {"Oak St", "Town", "City5"}, false};
    Info person6 = {{"Sarah", "Williams"}, {"River Rd", "District", "City6"}, false};
    Info person7 = {{"Emma", "Garcia"}, {"Sunset Blvd", "Beachside", "City7"}, false};
    Info person8 = {{"James", "Martinez"}, {"Mountain Ave", "Hilltop", "City8"}, false};
    Info person9 = {{"Olivia", "Robinson"}, {"Grove St", "Suburban", "City9"}, false};
    Info person10 = {{"Liam", "Moore"}, {"Valley Rd", "Rural", "City10"}, false};
    Info person11 = {{"Sophia", "Hernandez"}, {"Highway 5", "Outskirts", "City11"}, false};
    Info person12 = {{"William", "Lopez"}, {"Forest Ln", "Woodland", "City12"}, false};

    // Insert 6 values into hash table
    insertInfo(&hashTable, person1);
    insertInfo(&hashTable, person2);
    insertInfo(&hashTable, person3);
    insertInfo(&hashTable, person4);
    insertInfo(&hashTable, person5);
    insertInfo(&hashTable, person6);

    // Display the hash table contents
    printf("\n--------------------------------");
    printf("\nInitial Hash Table:");
    display(hashTable);

    // Test findPerson function
    printf("\n\nFinding person:");
    findPerson(hashTable, person3); // Find person3

    // Test deleteInfo function
    printf("\n\nDeleting person:");
    deleteInfo(&hashTable, person3); // Delete person3
    display(hashTable); // Display after deletion

    insertInfo(&hashTable, person7);
    insertInfo(&hashTable, person8);
    insertInfo(&hashTable, person9);
    insertInfo(&hashTable, person10);
    insertInfo(&hashTable, person11);
    insertInfo(&hashTable, person12);

    printf("\n--------------------------------");
    printf("\nNew Hash Table:");
    display(hashTable);

    return 0;
}