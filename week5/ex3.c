#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 50
#define ITER 50
#define YES 1
#define NO 1

/**
 * Declarations
 */

void *consumerFunc(void *),
        *producerFunc(void *);

pthread_t initThread(void *, void *);

/**
 * Buffer and stuff
 */


typedef struct buffer_struct {
    long buf[BUFFER_SIZE]; // The buffer for storing ints (or whatever)
    size_t len; // Amount of stored items
    short canProduce; // signaled when items are removed
    short canConsume; // signaled when items are added
} Buffer;

/**
 * Main
 */


int main() {
    Buffer buffer = {
            .len = 0,
            .canProduce = YES,
            .canConsume = YES
    };

    pthread_t tidProd = initThread(producerFunc, &buffer);
//    pthread_join(tidProd, NULL); // Waiting for producer thread to finish

    pthread_t tidCons = initThread(consumerFunc, &buffer);
    pthread_join(tidCons, NULL); // Waiting for consumer thread to work
}

/**
 * Producer and consumer functions
 */


void *producerFunc(void *arg) {
    Buffer *buffer = (Buffer *) arg;

    for (int i = 0; i < ITER; i++) {
        if (buffer->len < BUFFER_SIZE) buffer->canProduce = YES;

        // Emulating producing
        for (int j = 0; buffer->canProduce && j < BUFFER_SIZE / 2; j++) {
            buffer->buf[buffer->len] = random();
            (buffer->len)++;
            if (buffer->len >= BUFFER_SIZE) buffer->canProduce = NO;
        }

        printf("Produced %lu\n", buffer->buf[buffer->len - 1]);
        printf("Size %lu\n", buffer->len);

        // Waiting till next producing
        sleep(1);
    }

    pthread_exit(0);
}


void *consumerFunc(void *arg) {
    Buffer *buffer = (Buffer *) arg;

    for (int i = 0; i < ITER; i++) {
        if (buffer->len > 0) buffer->canConsume = YES;

        long mul = 1; // Resource-taking "consumer"

        // Consuming
        for (int j = 0; buffer->canConsume; j++) {
            mul *= (buffer->buf[buffer->len]);
            (buffer->len)--;
            if (buffer->len == 0) buffer->canConsume = NO;
        }

        // Outputting
        printf("Consumed %lu. Nyam-nyam!\n", mul);

        // Waiting till next consuming
        sleep(1);
    }

    pthread_exit(0);
}

/**
 * Initializing a thread
 * @param func
 */

pthread_t initThread(void *func, void *buffer) {
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, func, buffer);

    return tid;
}