#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

//GRAPH
void initGraph(int graph[MAX][MAX], int ver)
{
	int j, k;
	
	for(j = 0 ; j < ver ; j++){
		for(k = 0 ; k < ver ; k++){
			graph[j][k] = 0;
		}
	}
}

void addEdge(int graph[MAX][MAX], int l, int h)
{
	graph[l][h] = 1;
	graph[h][l] = 1;
}

void printGraph(int graph[MAX][MAX], int ver)
{
	int j, k;
	
	for(j = 0 ; j < ver ; j++){
		for(k = 0 ; k < ver ; k++){
			if(j == k){
				printf("\\ ");
			} else {
				printf("%d ", graph[j][k]);	
			}
		}
		printf("\n");
	}	
}

//LIST
//initialize it with A, B, C, D, E
void initList(AdjList *Alist, int ver)
{
	int i;
	
	for(i =0 ; i < ver ; i++){
		Alist->list[i] = malloc(sizeof(Node));
		Alist->list[i]->vertex = i + 65;
		Alist->list[i]->next = NULL;
	}
	Alist->count = ver;
}

void createList(int graph[MAX][MAX], AdjList *Alist)
{
	int j, k;
	NodePtr temp, newNode;

	for(j = 0 ; j < Alist->count ; j++){
		//set head as the actual vertex and next will be the adjacency list
		temp = Alist->list[j];

		for(k = 0 ; k < Alist->count ; k++){			
			//check if 1; 1 means there is an edge
			if(graph[j][k] == 1)
			{

				//create first a new node for vertex k
				newNode = malloc(sizeof(Node));
				if (newNode == NULL) {
                    fprintf(stderr, "Error allocating memory for new node\n");
                    exit(1);
                }
				newNode->vertex = k + 65;
				newNode->next = NULL;
				
				//traverse to the end
				while(temp->next != NULL){
					temp = temp->next;
				}
				
				//add the newNode
				temp->next = newNode;
			}
		}
	}
}

void printList(AdjList Alist)
{
	int i;
	NodePtr temp;
	
	for(i = 0 ; i < Alist.count ; i++)
	{
		printf("%c={", Alist.list[i]->vertex);
		temp = Alist.list[i]->next;
		while (temp != NULL){
			printf("%c ", temp->vertex);
			if(temp->next != NULL)
			{
				printf(", ");
			}
			temp = temp->next;
		}
		
		printf("}\n");
	}
}