#ifndef ALGO_LIST_IMPL_H
#define ALGO_LIST_IMPL_H

#include "list.h"

void dijkstraList(ListGraph *g, int src);
void bellmanFordList(ListGraph *g, int src);
void bfsList(ListGraph *g, int startNode);
void dfsList(ListGraph *g, int startNode);
void aStarList(ListGraph *g, int src, int dest);
void floydWarshallList(ListGraph *g);

#endif