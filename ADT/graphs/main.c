#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*	
	a graph of A, B, C, D, E 
	assuming that they are 0, 1, 2, 3, 4 
	respectively
*/
	
int main(int argc, char *argv[]) {
	int graph[MAX][MAX];
	int ver = 5;
	
	initGraph(graph, ver);
	
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	
	printGraph(graph, ver);
	
	return 0;
}
