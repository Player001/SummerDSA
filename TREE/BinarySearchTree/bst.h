#ifndef BST
#define BST

#include <stdbool.h>

typedef struct 
    {
        int day, month, year;
    } Date;

typedef struct 
    {
        char prodName[20];
        float prodPrice;
        int prodQty;
        Date expDate;
    } Product;

typedef struct node
    {
        Product item;
        struct node *left, *right;
    } NodeType, *NodePtr;

// Utility functions
void initTree(NodePtr T);
NodePtr createProd();
void printProd(Product item);
// void display(NodePtr T);
void freeTree(NodePtr *T);
int compareProd(Product prod1, Product prod2);

// BST Functions
void insertProd(NodePtr *T, Product nProd);
void deleteProd(NodePtr *T, char dProd);
void searchBFS(NodePtr T, char prod);           // for balance
void searchPreorder(NodePtr T, char *prod);     // for searching
void searchInorder(NodePtr T, char *prod);      // for sorting
void searchPostorder(NodePtr T, char *prod);    // for postfix expression

#endif