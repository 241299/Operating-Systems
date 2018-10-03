#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int main() {
    char **s;
    char foo[] = "Hello World";

    s = malloc(sizeof(char**));
    *s = foo;

    printf("s is %s\n", *s); // Meaning pointer? Or the whole string?

    s[0] = foo; // Useless operation
    printf("s[0] is %c\n", *s[0]); // Assuming first character

    return 0;
}