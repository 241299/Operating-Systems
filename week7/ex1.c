#include <stdio.h>

/**
 * Summation function for demo purposes
 * @param a The first term
 * @param b The second term
 * @return The sum of <code>a</code> and <code>b</code> if no overflow occurs
 */

int sum(int a, int b) {
    return a + b;
}


int main() {
    printf("Hello world!\n");
    if (sum(2, 2) == 5) {
        printf("Cruel world...");
    }
}