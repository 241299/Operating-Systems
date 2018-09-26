#include <unistd.h>
#include <memory.h>
#include <stdio.h>

#define BUF_SIZE 100

int main() {
    int descriptors[2];
    char str1[] = "Hello from";
    char str2[BUF_SIZE];

    if (!pipe(descriptors)) {
        if (fork()) {
            write(descriptors[1], str1, strlen(str1));
        } else {
            // Busy wait for data
            while (read(descriptors[0], str2, BUF_SIZE) == 0);

            printf("%s child!", str2);
        }
    }

    return 0;
}