#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned shared = 0, N = 3;

    for (int i = 0; i < N; ++i) {
        fork();
        printf("Hell %d\n", ++shared);
        sleep(5);
    }

    exit(0);
}