#ifndef GRAPH
#define GRAPH

#define MAX 100

typedef struct node{
	char vertex;
	struct node* next;
}Node, *NodePtr;

typedef struct {
	NodePtr list[MAX];
	int count;
} AdjList;

void initGraph(int graph[MAX][MAX], int ver);
void addEdge(int graph[MAX][MAX], int l, int h);
void printGraph(int graph[MAX][MAX], int ver);
void initList(AdjList *Alist, int ver);
void createList(int graph[MAX][MAX], AdjList *Alist);
void printList(AdjList Alist);

#endif
