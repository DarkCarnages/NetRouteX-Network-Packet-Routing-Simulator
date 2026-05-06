#include <stdio.h>
#include "flyod_warshall.h"
#include "utils.h"

void floydWarshall(Graph *g) {
    int V = g->V;

    int dist[MAX][MAX];
    int next[MAX][MAX];

    // Initialize
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            dist[i][j] = g->adj[i][j];

            if(i == j || g->adj[i][j] == INF)
                next[i][j] = -1;
            else
                next[i][j] = j;
        }
    }

    double start = getTime();

    // Core algorithm
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {

                if(dist[i][k] == INF || dist[k][j] == INF)
                    continue;

                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }

    double end = getTime();

    // Print Distance Matrix
    printf("\n--- All-Pairs Shortest Path Matrix ---\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }

    // Print Routing Tables for each node
    printf("\n--- Routing Tables (Floyd-Warshall) ---\n");

    for(int i = 0; i < V; i++) {
        printf("\nNode %d Routing Table:\n", i);
        printf("Dest\tCost\tNext Hop\n");

        for(int j = 0; j < V; j++) {
            if(i == j) {
                printf("%d\t0\t-\n", j);
            }
            else if(next[i][j] == -1) {
                printf("%d\tINF\t-\n", j);
            }
            else {
                printf("%d\t%d\t%d\n", j, dist[i][j], next[i][j]);
            }
        }
    }

    printf("\nExecution Time: %.9lf sec\n", end-start );
    char buffer[256];

sprintf(buffer, "Flyod Warshall | Time %.9lf", end-start);
logToFile("output/performance.txt", buffer);
logToFile("output/performance.txt", "\n");
}