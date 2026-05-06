#ifndef LIST_H
#define LIST_H
#include "config.h"


typedef struct Node {
    int vertex;
    int weight;
    struct Node *next;
} Node;

typedef struct {
    int V;
    Node *head[MAX];
} ListGraph;

void initListGraph(ListGraph *g, int V);
void addListEdge(ListGraph *g, int src, int dest, int weight);
void printListGraph(ListGraph *g);
void freeGraph(ListGraph *g);

#endif