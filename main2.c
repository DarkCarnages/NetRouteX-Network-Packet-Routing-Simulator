#include <stdio.h>

#include "list.h"
#include "algo_list_impl.h"

int main() {

    ListGraph lg;

    int V = 5;

    initListGraph(&lg, V);

    addListEdge(&lg, 0, 1, 2);
    addListEdge(&lg, 0, 2, 5);
    addListEdge(&lg, 1, 2, 3);
    addListEdge(&lg, 1, 3, 4);
    addListEdge(&lg, 2, 3, 1);
    addListEdge(&lg, 3, 4, 2);

    printListGraph(&lg);

    int choice;
    int src;
    int dest;

    while(1) {

        printf("\n====== ADJACENCY LIST ROUTING SIMULATOR ======\n");

        printf("\n1. Bellman-Ford (List)");
        printf("\n2. Dijkstra (List)");
        printf("\n3. Floyd-Warshall (List Init)");
        printf("\n4. A* Routing (List)");
        printf("\n5. BFS Traversal (List)");
        printf("\n6. DFS Traversal (List)");
        printf("\n7. Run All Algorithms");
        printf("\n8. Exit");

        printf("\n\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:

            printf("Enter source node: ");
            scanf("%d", &src);

            if(src < 0 || src >= lg.V) {
                printf("Invalid source node!\n");
                break;
            }

            bellmanFordList(&lg, src);
            break;

        case 2:

            printf("Enter source node: ");
            scanf("%d", &src);

            if(src < 0 || src >= lg.V) {
                printf("Invalid source node!\n");
                break;
            }

            dijkstraList(&lg, src);
            break;

        case 3:

            floydWarshallList(&lg);
            break;

        case 4:

            printf("Enter source and destination: ");
            scanf("%d %d", &src, &dest);

            if(src < 0 || src >= lg.V || dest < 0 || dest >= lg.V) {
                printf("Invalid nodes!\n");
                break;
            }

            aStarList(&lg, src, dest);
            break;

        case 5:

            printf("Enter start node: ");
            scanf("%d", &src);

            if(src < 0 || src >= lg.V) {
                printf("Invalid start node!\n");
                break;
            }

            bfsList(&lg, src);
            break;

        case 6:

            printf("Enter start node: ");
            scanf("%d", &src);

            if(src < 0 || src >= lg.V) {
                printf("Invalid start node!\n");
                break;
            }

            dfsList(&lg, src);
            break;

        case 7:

            printf("\n=== Bellman-Ford List ===\n");

            for(int i = 0; i < lg.V; i++) {
                bellmanFordList(&lg, i);
            }

            printf("\n=== Dijkstra List ===\n");

            for(int i = 0; i < lg.V; i++) {
                dijkstraList(&lg, i);
            }

            printf("\n=== Floyd-Warshall List ===\n");

            floydWarshallList(&lg);

            printf("\n=== BFS List ===\n");

            bfsList(&lg, 0);

            printf("\n=== DFS List ===\n");

            dfsList(&lg, 0);

            printf("\n=== A* List ===\n");

            aStarList(&lg, 0, 4);

            break;

        case 8:

            freeGraph(&lg);

            printf("Exiting...\n");
            return 0;

        default:

            printf("Invalid choice!\n");
        }
    }

    return 0;
}