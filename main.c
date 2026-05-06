#include <stdio.h>
#include "graph.h"
#include "bellman_ford.h"
#include "dijkstra.h"
#include "flyod_warshall.h"
#include "astar.h"
#include "bfs_dfs.h"
#include "comparision.h"
#include "simulation.h"

int main() {
    Graph g;

    loadGraphFromFile(&g, "input_graph.txt");
    printGraph(&g);

    // clear old performance file
    FILE *fp = fopen("output/performance.txt", "w");
    if(fp) fclose(fp);

    int choice, src, dest, mode;

    while(1) {
        printf("\n====== NETWORK ROUTING SIMULATOR ======\n");
        printf("1. Bellman-Ford (Distance Vector)\n");
        printf("2. Dijkstra (Link State)\n");
        printf("3. Floyd-Warshall (All-Pairs)\n");
        printf("4. A* Routing\n");
        printf("5. BFS Traversal\n");
        printf("6. DFS Traversal\n");
        printf("7. Run All Algorithms\n");
        printf("8. Show Performance Comparison\n");
        printf("9. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
        case 2:
            printf("\n1. Full Routing Table\n2. Specific Destination\nChoose mode: ");
            scanf("%d", &mode);

            printf("Enter source: ");
            scanf("%d", &src);

            if(src < 0 || src >= g.V) {
                printf("Invalid source! Range: 0 to %d\n", g.V - 1);
                break;
            }

            if(mode == 1) {
                if(choice == 1)
                    bellmanFord(&g, src);
                else
                    dijkstra(&g, src);
            }
            else if(mode == 2) {
                printf("Enter destination: ");
                scanf("%d", &dest);

                if(dest < 0 || dest >= g.V) {
                    printf("Invalid destination!\n");
                    break;
                }

                int path[MAX], len;

            aStar(&g, src, dest, path, &len);
                        
            if(len > 0)
                simulatePacket(path, len);
            }
            else {
                printf("Invalid mode\n");
            }
            break;

        case 3:
            floydWarshall(&g);
            break;

        case 4:
    printf("Available nodes: 0 to %d\n", g.V - 1);

    printf("Enter source and destination: ");
    scanf("%d %d", &src, &dest);

    if(src < 0 || src >= g.V || dest < 0 || dest >= g.V) {
        printf("Invalid nodes!\n");
        break;
    }

    int path[MAX], len;

    aStar(&g, src, dest, path, &len);

    if(len > 0)
        simulatePacket(path, len);

    break;

        case 5:
            printf("Enter start node: ");
            scanf("%d", &src);

            if(src < 0 || src >= g.V) {
                printf("Invalid node!\n");
                break;
            }

            bfs(&g, src);
            break;

        case 6:
            printf("Enter start node: ");
            scanf("%d", &src);

            if(src < 0 || src >= g.V) {
                printf("Invalid node!\n");
                break;
            }

            dfs(&g, src);
            break;

        case 7:
            printf("\n=== Bellman-Ford ===\n");
            for(int i = 0; i < g.V; i++)
                bellmanFord(&g, i);

            printf("\n=== Dijkstra ===\n");
            runDijkstraAllNodes(&g);

            printf("\n=== Floyd-Warshall ===\n");
            floydWarshall(&g);
            break;

        case 8:
            printComparison();
            break;

        case 9:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}