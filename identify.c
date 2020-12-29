#include <stdlib.h>
#include <stdio.h>
int identify() {
    int key;
    #if _WIN32
        key = 1;
        printf("Windows host\n");
    #endif
    #if __linux__
        key = 2;
        printf("Linux host\n");
    #endif
    return key;
}