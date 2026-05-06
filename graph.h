#ifndef GRAPH_H
#define GRAPH_H
#include "config.h"

typedef struct {
    int V;
    int adj[MAX][MAX];
} Graph;

void initGraph(Graph *g, int V);
void addEdge(Graph *g, int u, int v, int w);
void printGraph(Graph *g);
void loadGraphFromFile(Graph *g, const char *filename);

#endif