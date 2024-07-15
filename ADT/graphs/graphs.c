#include <stdio.h>
#include "graphs.h"

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
			printf("%d ", graph[j][k]);
		}
		printf("\n");
	}	
}
