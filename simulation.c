#include <stdio.h>
#include <windows.h>
#include "simulation.h"

void simulatePacket(int path[], int len) {

    printf("\n--- Packet Movement Simulation ---\n");

    for(int i = 0; i < len - 1; i++) {
        printf("Packet: [%d] -> [%d]\n", path[i], path[i+1]);
        Sleep(500);  // 0.5 second delay (Windows)
    }

    printf("Packet reached destination ✔\n");
}