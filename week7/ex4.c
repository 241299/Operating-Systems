#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

/**
 * Declaration of re_alloc function
 * @param p
 * @param size
 */

void *re_alloc(void *, unsigned int, unsigned int);

/**
 * Main
 */

int main() {
    unsigned int p_size = sizeof(char) * 100;

    // First allocation
    void *p = malloc(p_size);
    printf("Old pointer: %p\n", p);

    // Reallocation to be 8 times bigger
    p = re_alloc(p, p_size, p_size * 8);
    printf("New pointer: %p\n", p);

    return 0;
}


/**
 * Reallocating function definition
 * @param p The pointer to be reallocated
 * @param old_size The size of the data pointed by p
 * @param size The new size to be pointed to
 * @return A new pointer either to NULL (if size is 0), or to a new memory location
 * @attention The old contents of the p would be erased!
 */

void *re_alloc(void *p, unsigned int old_size, unsigned int size) {
    if (p == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(p);
        return NULL;
    }

    // Allocating memory and copying contents
    void *p2 = malloc(size);
    memcpy(p2, p, old_size);

    // Collecting garbage
    free(p);

    return p2;
}