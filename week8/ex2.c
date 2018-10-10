#include <memory.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MB * 1 << 20
#define GB * 1 << 30
#define second * 1

int main() {

    void *mem[10];

    for (int i = 0; i < 10; i++) {

        // Allocate 10 MB of memory
        mem[i] = malloc(10 MB);
        memset(mem[i], 0, 10 MB);

        sleep(1 second);
    }

    // Freeing the space
    for (int i = 0; i < 10; i++) {
        free(mem[i]);
    }

    return 0;
}