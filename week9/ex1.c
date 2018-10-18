#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define first_bit 1 << (sizeof(int) * 8 - 1) // 1000 0000 0000 0000 for 16-bit ints
#define lucky(p) (i % p == random() % p)

/*
 * Function declarations
 */

/**
* A function for parsing the string of space-separated ints
* @param s Pointer to the head of the null-terminated string
* @param arr Pointer to the memory allocated for an array (will be filled)
* @return The size of array
*/

int read_nums(char *s, int *arr);


/**
 * Implementation of aging algorithm simulator
 * @param ref_arr Array of page numbers as they are referenced
 * @param ref_len The length of input array
 * @param frames_count Number of available page frames
 * @param hit Hit parameter (output)
 * @param miss Miss parameter (output)
 * @note Clock ticks are chosen at random
 * @note The search is linear
 */

void aging_alg(const int *ref_arr, int ref_len, int frames_count, int *hit, int *miss);


/**
 * Finds a page in the working page frames
 * @param page A page number to find
 * @param frames_arr The array to search in
 * @param frames_len The length of the searched array
 * @return The index of page in the array or -1 if it was not found
 * @note The linear search is performed
 */

int find_page(int page, const int *frames_arr, int frames_len);


/**
 * Finds the page that was unused for a long time (having the least counter value)
 * @param counters_arr Where to search
 * @param counters_len
 * @return
 */

int find_least_page_index(const unsigned int *counters_arr, int counters_len);


/**
 * Shift the counters 1 position to the right
 * @param c_arr Array of counters
 * @param c_len The length of the array
 */

void shift_counters(unsigned int *c_arr, int c_len);


/*
 * Main
 */

int main() {
    /*
     * Input stuff
     */

    // Reading an array
    FILE *in = fopen("ex1_input.txt", "r");

    char *input_arr = malloc(sizeof(char) * 1 << 16); // Allocate 65536 bytes for a string (as in Java)
    fscanf(in, "%[^\n]", input_arr);

    int *arr = malloc(sizeof(int) * 1 << 15);
    int arr_len = read_nums(input_arr, arr);

    // Reading the number of page frames from stdin
    fprintf(stdout, "Input: %s\nNumber of page frames: ", input_arr);

    char *input_page_frames;
    fscanf(stdin, "%s", input_page_frames);
    int page_frames = (int) strtol(input_page_frames, NULL, 10);

    if (page_frames <= 0) {
        fprintf(stderr, "Incorrect input. Shutting down...");
        exit(3);
    } else printf("\n");


    /*
     * Algorithm
     */

    int hit = 0, miss = 0;
    aging_alg(arr, arr_len, page_frames, &hit, &miss);


    /*
     * Closing and outputting, blah-blah-blah
     */

    printf("\nHit/Miss ratio for Aging Algorithm: %d/%d\n", hit, miss);
    fclose(in);
}


/*
 * Function definitions
 */

int read_nums(char *s, int* arr) {
    int size = 0;
    char *p_end = malloc(sizeof(char*));
    int read;

    // Read the first number
    read = (int) strtol(s, &p_end, 10);
    if (errno != ERANGE) {
        *arr = read;
        arr++;
        size++;
    }

    // Read the remaining
    while(1) {
        char* prev = p_end; //Stop condition

        read = (int) strtol(p_end, &p_end, 10);
        if (errno != ERANGE && prev != p_end) {
            *arr = read;
            arr++;
            size++;
        } else break;
    }

    return size;
}


void aging_alg(const int *ref_arr, int ref_len, int frames_count, int *hit, int *miss) {
    int *frames = calloc((size_t) frames_count, sizeof(int));
    unsigned int *counters = calloc((size_t) frames_count, sizeof(int));

    for (int i = 0; i < ref_len; i++) {
        printf("\n[STEP %d]\n", i);

        // Emulate Clock Tick (with 1/4 probability)
        if lucky(4) {
            printf("Clock is ticking!\n");
            shift_counters(counters, frames_count);
        }

        int page = ref_arr[i];

        // Page reference
        int page_index = find_page(page, frames, frames_count);
        if (page_index != -1) {
            printf("Hit! Page: %d\n", page);

            // Increase counter if it wasn't done previously
            counters[page_index] += (counters[page_index] > first_bit)
                                    ? 0
                                    : first_bit;

            // Indicate hit
            (*hit)++;
        } else {
            printf("Miss! Page: %d\n", page);

            // Handle page fault
            int page_to_replace = find_least_page_index(counters, frames_count);

            // Output info (discard empty from output)
            if (frames[page_to_replace]) {
                printf("Removing page %d with counter %u\n",
                        frames[page_to_replace],
                        counters[page_to_replace]);
            }
            printf("Putting page %d to frame %d\n", page, page_to_replace);

            frames[page_to_replace] = page;
            counters[page_to_replace] = first_bit;

            // Indicate miss
            (*miss)++;
        }
    }
}


void shift_counters(unsigned int *c_arr, int c_len) {
    for (int i = 0; i < c_len; i++) {
        c_arr[i] >>= 1;
    }
}


int find_page(int page, const int *frames_arr, int frames_len) {
    for (int i = 0; i < frames_len; i++) {
        if (frames_arr[i] == page) return i;
    }

    return -1;
}


int find_least_page_index(const unsigned int *counters_arr, int counters_len) {
    int min_i = 0;
    for (int i = 1; i < counters_len; i++) {

        if (counters_arr[i] < counters_arr[min_i]) min_i = i;
    }

    return min_i;
}