#include "bst.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void initTree(NodePtr *T)
{
    *T = NULL;
}

NodePtr createProd()
{
    NodePtr newProd = malloc (sizeof(NodeType));
    //create newProd here
    return newProd;
}  

void printProd(Product item)
{
    printf("\n=================================================");
    printf("\nProduct Name: %s", item.prodName);
    printf("\nProduct Price: Php %.2lf", item.prodPrice);
    printf("\nAmount: %d", item.prodQty);
    printf("\nExpiration Date: %d %d %d", item.expDate.day, item.expDate.month, item.expDate.year);
}

void freeTree(NodePtr *T)
{
    if (*T == NULL)
    {
        return;
    }

    freeTree(&(*T)->left);
    freeTree(&(*T)->right);

    free(*T);
    *T = NULL;
}

int depth(NodePtr T)
{
    int leftDepth;
    int rightDepth;
    
    if (T == NULL) {
        return 0;
    }

    else {
        leftDepth = depth(T->left);
        rightDepth = depth(T->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

NodePtr findMax(NodePtr T)
{
    NodePtr current = T;

    while(current && current->right != NULL) {
        current = current->right;
    }

    return current;
}

NodePtr findMin(NodePtr T)
{
    NodePtr current = T;

    while(current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

void insertProd(NodePtr *T, Product nProd)
{
    if(*T == NULL) {
        *T = malloc(sizeof(NodeType));
        (*T)->item = nProd;
        (*T)->left = NULL;
        (*T)->right = NULL;
        return;
    }
    
    if(strcmp(nProd.prodName, (*T)->item.prodName) < 0) {
        insertProd(&(*T)->left, nProd);
    }

    else if(strcmp(nProd.prodName, (*T)->item.prodName) > 0) {
        insertProd(&(*T)->right, nProd);
    }

    else {
        return;
    }
}

void deleteProd(NodePtr *T, char *dProd)
{
    NodePtr temp;
    int leftDepth, rightDepth;

    if(*T == NULL) {
        return;
    }

    if (strcmp(dProd, (*T)->item.prodName) < 0) {
        deleteProd(&(*T)->left, dProd);
    }

    else if (strcmp(dProd, (*T)->item.prodName) > 0) {
        deleteProd(&(*T)->right, dProd);
    }

    else {
        //node with one child or no child
        if ((*T)->left == NULL) {
            temp = *T;
            *T = (*T)->right;
            free(temp);
        }    

        else if ((*T)->right == NULL) {
            temp = *T;
            *T = (*T)->left;
            free(temp);    
        }
        //node with both child
        else {
            leftDepth = depth((*T)->left);
            rightDepth = depth((*T)->right);

            if (leftDepth >= rightDepth) {
                temp = findMax((*T)->left);
            }

            else {
                temp = findMin((*T)->right);
            }


            (*T)->item = temp->item;

            if (leftDepth >= rightDepth) {
                deleteProd(&(*T)->left, dProd);
            } 

            else {
                deleteProd(&(*T)->right, dProd);
            }
        }
    }
}

void searchPreorder(NodePtr T, char *prod)
{
    if(T == NULL) {
        return;
    }

    printProd(T->item);
    searchPreorder(T->left, prod);
    searchPreorder(T->right, prod);
}

void searchInorder(NodePtr T, char *prod)
{
    if(T == NULL) {
        return;
    }

    searchPreorder(T->left, prod);
    printProd(T->item);
    searchPreorder(T->right, prod);
}

void searchPostorder(NodePtr T, char *prod)
{
    if(T == NULL) {
        return;
    }

    searchPreorder(T->left, prod);
    searchPreorder(T->right, prod);
    printProd(T->item);
}