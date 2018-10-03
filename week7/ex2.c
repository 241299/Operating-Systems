#include <stdio.h>
#include <stdlib.h>

/*
 * Function declarations
 */

void arr_fill_inc(int *, int),
        arr_print(int *, int);

int read();


/**
 * Main method
 */

int main() {
    printf("Welcome!\nPlease, enter the number of elements in the array: ");

    int N = read();
    int *array = malloc(sizeof(int) * N);

    arr_fill_inc(array, N);

    arr_print(array, N);

    free(array);
}


/**
 * Reading the integer from the input
 * @return
 */

int read() {
    char *p_err,
            *input = malloc(sizeof(char) * 10);

    scanf("%s", input);
    long result = strtol(input, &p_err, 10);

    if (result == 0) {
        printf("Invalid input\n");
        exit(-1);
    }

    return (int) result;
}


/**
 * Filling an array with incremental values
 * @param arr_len The length of the array
 */

void arr_fill_inc(int *array, int arr_len) {
    for (int i = 0; i < arr_len; i++) {
        array[i] = i;
    }
}


/**
 * Print the array using buffered print func
 * @param arr_len The length of the array
 */

void arr_print(int *array, int arr_len) {
    for (int i = 0; i < arr_len - 1; i++) {
        printf("%d, ", array[i]);
    }

    // Printing the last element and flushing the buffer
    printf("%d\n", array[arr_len - 1]);
}