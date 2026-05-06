#include <stdio.h>
#include "bfs_dfs.h"
#include "utils.h"

void bfs(Graph *g, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    double startTime = getTime();

    visited[start] = 1;
    queue[rear++] = start;

    printf("\n--- BFS Traversal ---\n");

    while(front < rear) {
        int u = queue[front++];
        printf("%d ", u);

        for(int v = 0; v < g->V; v++) {
            if(g->adj[u][v] != INF && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }

    double endTime = getTime();
    printf("\nExecution Time: %.9lf sec\n", endTime - startTime);
     char buffer[256];

    sprintf(buffer, "BFS |SRC: %d | Time %.9lf",start, endTime-startTime);
    logToFile("output/performance.txt", buffer);
    logToFile("output/performance.txt", "\n");
}

void dfsUtil(Graph *g, int u, int visited[]) {
    visited[u] = 1;
    printf("%d ", u);

    for(int v = 0; v < g->V; v++) {
        if(g->adj[u][v] != INF && !visited[v]) {
            dfsUtil(g, v, visited);
        }
    }
}

void dfs(Graph *g, int start) {
    int visited[MAX] = {0};

    double startTime = getTime();

    printf("\n--- DFS Traversal ---\n");
    dfsUtil(g, start, visited);

    double endTime = getTime();
    printf("\nExecution Time: %.9lf sec\n", endTime - startTime);
     
    
    char buffer[256];

    sprintf(buffer, "DFS | SRC: %d | Time %.9lf",start , endTime-startTime);
    logToFile("output/performance.txt", buffer);
    logToFile("output/performance.txt", "\n");
}