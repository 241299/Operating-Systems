#include <stdio.h>

#define READ_LEN 20

int main() {
    FILE *f = fopen("/dev/random", "r");

    char rnd[READ_LEN + 1];
    fgets(rnd, READ_LEN + 1, f);

    printf("%s", rnd);
    fflush(stdout);

    return 0;
}