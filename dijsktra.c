#include <stdio.h>
#include "dijkstra.h"
#include "utils.h"

int minDistance(int dist[], int visited[], int V) {
    int min = INF, index = -1;

    for(int i = 0; i < V; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(Graph *g, int src) {
    int V = g->V;
    int dist[MAX], visited[MAX], parent[MAX];

    for(int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    double start = getTime();

    for(int i = 0; i < V - 1; i++) {
        int u = minDistance(dist, visited, V);
        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < V; v++) {
            if(!visited[v] && g->adj[u][v] != INF &&
               dist[u] + g->adj[u][v] < dist[v]) {

                dist[v] = dist[u] + g->adj[u][v];
                parent[v] = u;
            }
        }
    }

    double end = getTime();

    printf("\n--- Link State Routing Table (Node %d) ---\n", src);
    printf("Dest\tCost\tNext Hop\n");

    for(int i = 0; i < V; i++) {
        if(i == src) {
            printf("%d\t0\t-\n", i);
            continue;
        }

        if(dist[i] == INF) {
            printf("%d\tINF\t-\n", i);
            continue;
        }

        int next = i;
        while(parent[next] != src && parent[next] != -1)
            next = parent[next];

        printf("%d\t%d\t%d\n", i, dist[i], next);
    }

    printf("Execution Time: %.9lf sec\n", end - start);
    char buffer[256];

    sprintf(buffer, "Dijsktra | Src %d | Time %.9lf", src, end-start);
    logToFile("output/performance.txt", buffer);
    logToFile("output/performance.txt", "\n");
}

void runDijkstraAllNodes(Graph *g) {
    for(int i = 0; i < g->V; i++) {
        dijkstra(g, i);
    }
}