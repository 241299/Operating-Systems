#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void catch_signal(int sig) {
    char *out;

    switch (sig) {
        case SIGKILL:
            out = "SIGKILL";
            break;
        case SIGSTOP:
            out = "SIGSTOP";
            break;
        case SIGUSR1:
            out = "SIGUSR1";
            break;
        default:
            out = "Unknown signal";
    }

    printf("Received %s. Terminating the app...", out);
    exit(0);
}

int main() {
    void (*func_ptr)(int);

    signal(SIGKILL, catch_signal);
    signal(SIGUSR1, catch_signal);
    signal(SIGSTOP, catch_signal);

    signal(SIGINT, catch_signal); // "Unknown" signal

    // Lazy waiting
    while(1) sleep(1);
}