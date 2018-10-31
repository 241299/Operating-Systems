#include <stdio.h>
#include <unistd.h>

int main() {
    char *s = "Hello";

    // No need to set up stdout to line buffer, as it is already line buffer

    while(*s != '\0') {
        printf("%c", *s);
        sleep(1);
        s++;
    }

    // Flushing all 5 buffered characters
    fflush(stdout);
}