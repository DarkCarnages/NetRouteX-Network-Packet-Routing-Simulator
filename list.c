#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initListGraph(ListGraph *g, int V) {
    g->V = V;

    for(int i = 0; i < V; i++) {
        g->head[i] = NULL;
    }
}

void addListEdge(ListGraph *g, int src, int dest, int weight) {

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = g->head[src];
    g->head[src] = newNode;

    Node *newNode2 = (Node *)malloc(sizeof(Node));
    newNode2->vertex = src;
    newNode2->weight = weight;
    newNode2->next = g->head[dest];
    g->head[dest] = newNode2;
}

void printListGraph(ListGraph *g) {

    printf("\n--- Adjacency List ---\n");

    for(int i = 0; i < g->V; i++) {

        printf("%d -> ", i);

        Node *temp = g->head[i];

        while(temp != NULL) {
            printf("(%d,%d) -> ", temp->vertex, temp->weight);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

void freeGraph(ListGraph *g) {

    for(int i = 0; i < g->V; i++) {

        Node *temp = g->head[i];

        while(temp != NULL) {
            Node *del = temp;
            temp = temp->next;
            free(del);
        }
    }
}