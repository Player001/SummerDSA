#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	NodePtr root;
    initTree(&root);

    Product p1 = {"Apple", 1.0, 10, {1, 1, 2023}};
    Product p2 = {"Banana", 0.5, 20, {1, 2, 2023}};
    Product p3 = {"Cherry", 2.0, 15, {1, 3, 2023}};
    Product p4 = {"Date", 3.0, 5, {1, 4, 2023}};
    Product p5 = {"Elderberry", 4.0, 8, {1, 5, 2023}};
    Product p6 = {"Fig", 5.0, 12, {1, 6, 2023}};

    insertProd(&root, p1);
    insertProd(&root, p2);
    insertProd(&root, p3);
    insertProd(&root, p4);
    insertProd(&root, p5);
    insertProd(&root, p6);

    printf("Inorder traversal before deletion:");
    searchInorder(root, "");

    deleteProd(&root, "Cherry");

    printf("\n\nInorder traversal after deletion:");
    searchInorder(root, "");

    // Free the entire tree
    freeTree(&root);

    return 0;
}
