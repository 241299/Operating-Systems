#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pid;

    if ((pid = fork()) == 0) {
        printf("Hello from parent [PID %d]\n", pid);
    } else printf("Hello from child [PID %d]\n", pid);

    exit(0);
}