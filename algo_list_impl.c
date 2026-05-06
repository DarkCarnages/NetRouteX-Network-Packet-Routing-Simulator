#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "utils.h"


int minDistance(int dist[], int visited[], int V) {
    int min = INF;
    int idx = -1;

    for(int i = 0; i < V; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    }

    return idx;
}


void dijkstraList(ListGraph *g, int src) {

    int dist[MAX];
    int visited[MAX];
    int parent[MAX];

    for(int i = 0; i < g->V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    double start = getTime();

    for(int i = 0; i < g->V - 1; i++) {

        int u = minDistance(dist, visited, g->V);

        if(u == -1)
            break;

        visited[u] = 1;

        Node *temp = g->head[u];

        while(temp != NULL) {

            int v = temp->vertex;
            int w = temp->weight;

            if(!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }

            temp = temp->next;
        }
    }

    double end = getTime();

    printf("\n--- Dijkstra Using Adjacency List ---\n");

    for(int i = 0; i < g->V; i++) {
        printf("%d -> %d\n", i, dist[i]);
    }

    printf("Execution Time: %.9lf sec\n", end - start);
}


void bellmanFordList(ListGraph *g, int src) {

    int dist[MAX];
    int parent[MAX];

    for(int i = 0; i < g->V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    double start = getTime();

    for(int k = 0; k < g->V - 1; k++) {

        for(int i = 0; i < g->V; i++) {

            Node *temp = g->head[i];

            while(temp != NULL) {

                int j = temp->vertex;
                int w = temp->weight;

                if(dist[i] != INF && dist[i] + w < dist[j]) {
                    dist[j] = dist[i] + w;
                    parent[j] = i;
                }

                temp = temp->next;
            }
        }
    }

    double end = getTime();

    printf("\n--- Bellman Ford Using Adjacency List ---\n");

    for(int i = 0; i < g->V; i++) {
        printf("%d -> %d\n", i, dist[i]);
    }

    printf("Execution Time: %.9lf sec\n", end - start);
}


void bfsList(ListGraph *g, int startNode) {

    int visited[MAX] = {0};
    int queue[MAX];

    int front = 0;
    int rear = 0;

    double start = getTime();

    visited[startNode] = 1;
    queue[rear++] = startNode;

    printf("\n--- BFS Using Adjacency List ---\n");

    while(front < rear) {

        int u = queue[front++];

        printf("%d ", u);

        Node *temp = g->head[u];

        while(temp != NULL) {

            int v = temp->vertex;

            if(!visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }

            temp = temp->next;
        }
    }

    double end = getTime();

    printf("\nExecution Time: %.9lf sec\n", end - start);
}


void dfsUtilList(ListGraph *g, int u, int visited[]) {

    visited[u] = 1;

    printf("%d ", u);

    Node *temp = g->head[u];

    while(temp != NULL) {

        int v = temp->vertex;

        if(!visited[v]) {
            dfsUtilList(g, v, visited);
        }

        temp = temp->next;
    }
}


void dfsList(ListGraph *g, int startNode) {

    int visited[MAX] = {0};

    double start = getTime();

    printf("\n--- DFS Using Adjacency List ---\n");

    dfsUtilList(g, startNode, visited);

    double end = getTime();

    printf("\nExecution Time: %.9lf sec\n", end - start);
}


int heuristic(int u, int v) {
    return 0;
}


int getMinNode(int f[], int visited[], int V) {

    int min = INF;
    int idx = -1;

    for(int i = 0; i < V; i++) {

        if(!visited[i] && f[i] < min) {
            min = f[i];
            idx = i;
        }
    }

    return idx;
}


void aStarList(ListGraph *g, int src, int dest) {

    int gCost[MAX];
    int fCost[MAX];
    int parent[MAX];
    int visited[MAX];

    for(int i = 0; i < g->V; i++) {
        gCost[i] = INF;
        fCost[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    gCost[src] = 0;
    fCost[src] = heuristic(src, dest);

    double start = getTime();

    for(int i = 0; i < g->V; i++) {

        int u = getMinNode(fCost, visited, g->V);

        if(u == -1)
            break;

        if(u == dest)
            break;

        visited[u] = 1;

        Node *temp = g->head[u];

        while(temp != NULL) {

            int v = temp->vertex;
            int w = temp->weight;

            if(!visited[v]) {

                int newCost = gCost[u] + w;

                if(newCost < gCost[v]) {
                    gCost[v] = newCost;
                    fCost[v] = gCost[v] + heuristic(v, dest);
                    parent[v] = u;
                }
            }

            temp = temp->next;
        }
    }

    double end = getTime();

    printf("\n--- A* Using Adjacency List ---\n");

    if(gCost[dest] == INF) {
        printf("No Path Found\n");
        return;
    }

    int path[MAX];
    int len = 0;

    for(int v = dest; v != -1; v = parent[v]) {
        path[len++] = v;
    }

    printf("Path: ");

    for(int i = len - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }

    printf("\nCost: %d\n", gCost[dest]);
    printf("Execution Time: %.9lf sec\n", end - start);
}


void floydWarshallList(ListGraph *g) {

    int dist[MAX][MAX];

    for(int i = 0; i < g->V; i++) {
        for(int j = 0; j < g->V; j++) {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for(int i = 0; i < g->V; i++) {

        Node *temp = g->head[i];

        while(temp != NULL) {
            dist[i][temp->vertex] = temp->weight;
            temp = temp->next;
        }
    }

    double start = getTime();

    for(int k = 0; k < g->V; k++) {
        for(int i = 0; i < g->V; i++) {
            for(int j = 0; j < g->V; j++) {

                if(dist[i][k] == INF || dist[k][j] == INF)
                    continue;

                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    double end = getTime();

    printf("\n--- Floyd Warshall Using Adjacency List Initialization ---\n");

    for(int i = 0; i < g->V; i++) {
        for(int j = 0; j < g->V; j++) {

            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }

        printf("\n");
    }

    printf("Execution Time: %.9lf sec\n", end - start);
}




