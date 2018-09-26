#include <unistd.h>
#include <memory.h>
#include <stdio.h>

#define BUF_SIZE 100

int main() {
    int descriptors[2];
    char str1[] = "Hello world";
    char str2[BUF_SIZE];

    if (!pipe(descriptors)) {
        write(descriptors[1], str1, strlen(str1));
        read(descriptors[0], str2, BUF_SIZE);
    }

    return 0;
}