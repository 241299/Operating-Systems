#include <pthread.h>
#include <stdio.h>

#define N 5

void *pFunction(void *tID);
void initThread(int);

int main() {
    for (int i = 0; i < N; i++) {
        initThread(i);
    }
}

void initThread(int tID) {
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, pFunction, &tID);

    //Uncomment to fix order
    //pthread_join(tid, NULL);
}

void *pFunction(void *tID) {
    printf("%i\n", *(int*)tID);

    pthread_exit(0);
}