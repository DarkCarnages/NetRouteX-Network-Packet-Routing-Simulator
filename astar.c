#include <stdio.h>
#include "astar.h"
#include "utils.h"
#include "simulation.h"
int heuristic(int u, int v) {
    return 0; // you can improve later
}

int getMinNode(int f[], int visited[], int V) {
    int min = INF, idx = -1;

    for(int i = 0; i < V; i++) {
        if(!visited[i] && f[i] < min) {
            min = f[i];
            idx = i;
        }
    }
    return idx;
}

void aStar(Graph *g, int src, int dest,int path[], int *len) {
    int V = g->V;

    int gCost[MAX], fCost[MAX], parent[MAX], visited[MAX];

    for(int i = 0; i < V; i++) {
        gCost[i] = INF;
        fCost[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    gCost[src] = 0;
    fCost[src] = heuristic(src, dest);

    double start = getTime();

    for(int i = 0; i < V; i++) {
        int u = getMinNode(fCost, visited, V);
        if(u == -1) break;

        if(u == dest) break;

        visited[u] = 1;

        for(int v = 0; v < V; v++) {
            if(g->adj[u][v] != INF) {
                int newCost = gCost[u] + g->adj[u][v];

                if(newCost < gCost[v]) {
                    gCost[v] = newCost;
                    fCost[v] = gCost[v] + heuristic(v, dest);
                    parent[v] = u;
                }
            }
        }
    }

    double end = getTime();

    // Print path
    printf("\n--- A* Path from %d to %d ---\n", src, dest);

   if(gCost[dest] == INF) {
    printf("No path found\n");
    *len = 0;
    return;
}

int temp[MAX], count = 0;

for(int v = dest; v != -1; v = parent[v]) {
    temp[count++] = v;
}

// reverse path
*len = 0;
for(int i = count - 1; i >= 0; i--) {
    path[(*len)++] = temp[i];
}

printf("\n--- A* Path from %d to %d ---\n", src, dest);

printf("Path: ");
for(int i = 0; i < *len; i++)
    printf("%d ", path[i]);

printf("\nCost: %d\n", gCost[dest]);
printf("Execution Time: %.9lf sec\n", end - start);
    char buffer[256];

sprintf(buffer, "A_Star | Src %d | Time %.9lf", src, end-start);
logToFile("output/performance.txt", buffer);
logToFile("output/performance.txt", "\n");
}