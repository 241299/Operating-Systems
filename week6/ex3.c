#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void catch_signal(int sig) {
    printf("Received SIGINT. Terminating the app...");
    exit(0);
}

int main() {
    void (*func_ptr)(int);
    signal(SIGINT, catch_signal);

    // Lazy waiting
    while(1) sleep(1);
}