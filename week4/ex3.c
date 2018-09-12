#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#define LIMIT 256 // Limit for a string length

int main() {
    char s[LIMIT];

    for (;;) {
        scanf("%s", s);
        if (strncmp(s, "exit", LIMIT) == 0) {
            exit(0);
        }
        system(s);
    }
}