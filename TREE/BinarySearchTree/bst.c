#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void initTree(NodePtr T)
    {
        T->item.prodName[0] = '\0';
        T->left = NULL;
        T->right = NULL;
    }

NodePtr createProd()
    {
        NodePtr newProd = malloc (sizeof(NodeType));
        //create newProd here
        return newProd;
    }  

void printProd(Product item)
    {
        printf("\nProduct Name: %s", item.prodName);
        printf("\nProduct Price: %.2lf", item.prodPrice);
        printf("\nAmount: %d", item.prodQty);
        printf("\nExpiration Date: %d %d %d", item.expDate.day, item.expDate.month, item.expDate.year);
    }

// void display(NodePtr T){
//     NodePtr *trav = &T;   
// }

void insertProd(NodePtr *T, Product nProd)
    {
        if(*T == NULL)
            {
                (*T)->item = nProd;
                return;
            }
        
        if(strcmp(nProd.prodName, (*T)->item.prodName) < 0)
            {
                insertProd(&(*T)->left, nProd);
            }

        else if(strcmp(nProd.prodName, (*T)->item.prodName) > 0)
            {
                insertProd(&(*T)->right, nProd);
            }

        else
            {
                return;
            }
    }

void deleteProd(NodePtr *T, char dProd)
    {
        
    }

void searchPreorder(NodePtr T, char *prod)
    {
        if(T == NULL)
            {
                return;
            }

        printProd(T->item);
        searchPreorder(T->left, prod);
        searchPreorder(T->right, prod);
    }

void searchInorder(NodePtr T, char *prod)
    {
        if(T == NULL)
            {
                return;
            }

        searchPreorder(T->left, prod);
        printProd(T->item);
        searchPreorder(T->right, prod);
    }

void searchPostorder(NodePtr T, char *prod)
    {
        if(T == NULL)
            {
                return;
            }

        searchPreorder(T->left, prod);
        searchPreorder(T->right, prod);
        printProd(T->item);
    }