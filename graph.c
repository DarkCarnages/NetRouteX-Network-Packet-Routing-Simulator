#include <stdio.h>
#include "graph.h"

void initGraph(Graph *g, int V) {
    g->V = V;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i == j)
                g->adj[i][j] = 0;
            else
                g->adj[i][j] = INF;
        }
    }
}

void addEdge(Graph *g, int u, int v, int w) {
    g->adj[u][v] = w;
    g->adj[v][u] = w;
}

void printGraph(Graph *g) {
    printf("\n--- Adjacency Matrix ---\n");
    for(int i=0;i<g->V;i++){
        for(int j=0;j<g->V;j++){
            if(g->adj[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

void loadGraphFromFile(Graph *g, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if(!fp){
        printf("Error opening file\n");
        return;
    }

    int V, E;
    fscanf(fp, "%d %d", &V, &E);

    initGraph(g, V);

    for(int i=0;i<E;i++){
        int u, v, w;
        fscanf(fp, "%d %d %d", &u, &v, &w);
        addEdge(g, u, v, w);
    }

    fclose(fp);
}