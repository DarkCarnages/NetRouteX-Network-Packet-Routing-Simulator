#include <stdio.h>
#include <windows.h>
#include "utils.h"

double getTime() {
    static LARGE_INTEGER freq;
    static int init = 0;

    if(!init){
        QueryPerformanceFrequency(&freq);
        init = 1;
    }

    LARGE_INTEGER t;
    QueryPerformanceCounter(&t);

    return (double)t.QuadPart / freq.QuadPart;
}

void logToFile(const char *filename, const char *content) {
    FILE *fp = fopen(filename, "a");
    if(fp == NULL) return;

    fprintf(fp, "%s\n", content);
    fclose(fp);
}