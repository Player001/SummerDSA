#include "openhash.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Initialize the hash table
    Hash_List H;
    initTable(&H, 6);
	InfoPtr curr;
	InfoPtr toFree;

    // Adding sample data
    Info person1 = {{"John", "Doe"}, {"123 Main St", "Barangay 1", "City A"}, NULL};
    Info person2 = {{"Jane", "Smith"}, {"456 Elm St", "Barangay 2", "City B"}, NULL};
    Info person3 = {{"Alice", "Brown"}, {"789 Oak St", "Barangay 3", "City C"}, NULL};
    Info person4 = {{"Bob", "Johnson"}, {"101 Pine St", "Barangay 4", "City D"}, NULL};

    insertInfo(&H, person1);
    insertInfo(&H, person2);
    insertInfo(&H, person3);
    insertInfo(&H, person4);

    printf("\nBefore deletion:");
    display(H);

    // Deleting a person
    deleteInfo(&H, person2);

    printf("\n\nAfter deletion:");
    display(H);

    // Free the allocated memory
    for (int i = 0; i < H.size; i++) {
        curr = H.list[i];
        while (curr != NULL) {
            toFree = curr;
            curr = curr->next;
            free(toFree);
        }
    }
    free(H.list);

    return 0;
}
