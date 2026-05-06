#include <stdio.h>

void printComparison() {
    FILE *fp = fopen("output/performance.txt", "r");

    if(!fp){
        printf("No performance data found\n");
        return;
    }

    char line[256];

    printf("\n=== Performance Comparison ===\n");
    printf("Algorithm\tDetails\t\tTime\n");
    printf("\n");

    while(fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
}