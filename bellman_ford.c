#include <stdio.h>
#include <time.h>
#include "bellman_ford.h"
#include "utils.h"

void bellmanFord(Graph *g, int src) {
    int V = g->V;
    int dist[MAX], parent[MAX];

    for(int i=0;i<V;i++){
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    
    double start = getTime();
    for(int k=0;k<V-1;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(g->adj[i][j] != INF && dist[i] != INF &&
                   dist[i] + g->adj[i][j] < dist[j]) {

                    dist[j] = dist[i] + g->adj[i][j];
                    parent[j] = i;
                }
            }
        }
    }

    double end = getTime();
    double time_taken = end - start;
    printf("\n--- Distance Vector Routing Table (Node %d) ---\n", src);
    printf("Dest\tCost\tNext Hop\n");

    for(int i=0;i<V;i++){
        int next = i;

        if(i == src){
            printf("%d\t0\t-\n", i);
            continue;
        }

        while(parent[next] != src && parent[next] != -1)
            next = parent[next];

        if(parent[i] == -1)
            printf("%d\tINF\t-\n", i);
        else
            printf("%d\t%d\t%d\n", i, dist[i], next);
    }

    printf("Execution Time: %lf sec\n", time_taken);
    char buffer[256];

    sprintf(buffer, "Bellman_Ford | Src %d | Time %.9lf", src, time_taken);
    logToFile("output/performance.txt", buffer);
    logToFile("output/performance.txt", "\n");
}