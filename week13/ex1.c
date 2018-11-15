#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>

#define BUFFER_SIZE 64
#define DEFAULT_PROC_CNT 16
#define STATE_CHANGED 1
#define STATE_NOT_CHANGED 2
#define STATE_SUCCESS 3
#define DUMP printf("Dump: available = %d", available[0]);for (int i = 1; i < res_c; i++) {printf(", %d", available[i]); }printf("\n\n");

/*
 * Function declarations
 */

void prepare_input(
        FILE *file,                             // File to read input from
        int *res_c, int *proc_c,                // Amount of resources and processes (dimensions of matrices)
        int **existing, int **available,        // Arrays of existing and available resources' counts
        int ***cur_allocation, int ***req       // Matrices of current allocations and requests
);

int compare_vec(int len, const int *vec1,
                const int *vec2); // Compares two vectors of length `len`. -1 is returned if the first is less than the second, 1 otherwise

void add_vec(int len, int *dest, const int *src);           // Adds up two vectors of length `len`

void solve(int *ret_c, int **ret_v,             // Returned values and their count
           int res_c, int proc_c,
           int *existing, int *available,
           int **cur_allocation, int **req
);


/*
 * Main (just puppet master)
 */

int main(int argc, char **argv) {
    /* Input stuff */
    FILE *file;
    if (argc > 1) {
        file = fopen(argv[1], "r");

        if (file == NULL) {
            fprintf(stderr, "Error opening file %s\n", argv[1]);
            exit(2);
        }
    } else {
        fprintf(stderr, "Error: no input file specified\n");
        exit(1);
    }

    /* Declaring working variables, blah-blah-blah */
    int
            res_c,
            proc_c,
            *existing,       // Existing resources array pointer
            *available;

    int
            **cur_allocation,
            **req;

    prepare_input(file, &res_c, &proc_c, &existing, &available, &cur_allocation, &req);

    /* Prepare solver */
    int
            *ret_c = malloc(sizeof(int)),               // Count of the numbers returned
            **ret_v = malloc(sizeof(int *));            // Values returned

    solve(ret_c, ret_v, res_c, proc_c, existing, available, cur_allocation, req);

//    exit(0);

    /* Output */
    if (*ret_c == 0) {
        printf("No deadlock is detected\n");
    } else if (*ret_c == 1) {
        printf("Warning: process %c cannot be run on current resources\n", 'A' + (*ret_v)[0]);
    } else {
        printf("Deadlock detected in processes ");
        printf("%c", 'A' + (*ret_v)[0]);

        for (int i = 1; i < (*ret_c) - 1; i++) {
            printf(", %c", 'A' + (*ret_v)[i]);
        }

        printf(" and %c", 'A' + (*ret_v)[*ret_c - 1]);
    }
}


/*
 * Function definitions
 */


/**
 * The (only) interesting function. Implements the deadlock checking algorithm
 */

void solve(int *ret_c, int **ret_v,
           int res_c, int proc_c,
           int *existing, int *available,
           int **cur_allocation, int **req
) {

    /* Marking all the processes to be traversed */
    int *marked_proc = malloc(sizeof(int) * proc_c);

    for (int i = 0; i < proc_c; i++) {
        marked_proc[i] = i;
    }

    int
            state,           // The current state. Used to check at which state does the algorithm halt
            marked = proc_c; // Counter for the number of processes still left to traverse

    /* Looping until either a deadlock found or all the processes are traversed */
    do {
        state = STATE_NOT_CHANGED;
        printf("Unmarked left: %d\n", marked);

        for (int i = 0; i < proc_c; i++) {

            /* Check whether the process was already traversed */
            if (marked_proc[i] != -1) {

                printf("Process %c %s\n", 'A' + i, (compare_vec(res_c, available, req[i]) > 0) ? "fits" : "doesn't fit");

                /* Check if existing resources can satisfy the needs of the i-th process */
                if (compare_vec(res_c, available, req[i]) > 0) {
                    add_vec(res_c, available, cur_allocation[i]);

                    marked_proc[i] = -1;    // Mark the process as traversed
                    state = STATE_CHANGED;  // Identify that one process resolved
                    marked--;               // Decrement count of left processes
                }
            }
        }

        if (!marked) state = STATE_SUCCESS;

        DUMP
    } while (state == STATE_CHANGED);

    if (state == STATE_SUCCESS) {
        *ret_c = 0;
        return;
    } else {
        *ret_c = 0;
        *ret_v = malloc(sizeof(int) * marked);

        for (int i = 0; i < proc_c; i++) {
            if (marked_proc[i] != -1) {
                (*ret_v)[*ret_c] = marked_proc[i]; // Filling the array of deadlocked processes
                (*ret_c)++;
            }
        }
    }
}


int compare_vec(int len, const int *vec1, const int *vec2) {
    for (int i = 0; i < len; i++) {
        if (vec1[i] < vec2[i]) return -1;
    }
    return 1;
}


void add_vec(int len, int *dest, const int *src) {
    for (int i = 0; i < len; i++) dest[i] += src[i];
}


int read_str(FILE *file, char **dest) {
    char buffer[BUFFER_SIZE];

    /* Read string from file and check for errors */
    if (fgets(buffer, BUFFER_SIZE, file) == NULL) {
        fprintf(stderr, "Unable to read file\n");
        exit(2);
    }

    *dest = strdup(buffer);
    return (int) strlen(*dest);
}


/**
 * Parses the input string read from file
 * @param s What to parse
 * @param arr Where to write the output
 * @param arr_len Where to write the read amount
 */

void parse_str(char *s, int **arr, int *arr_len) {
    /* Create buffer for putting integers */
    int tmp_arr[BUFFER_SIZE];
    int size = 0;

    /*
     * Reading
     */

    char *p_end = malloc(sizeof(char *));
    int read;

    /* Read the first number */
    read = (int) strtol(s, &p_end, 10);
    if (errno != ERANGE) {
        tmp_arr[size++] = read;
    }

    /* Read the remaining */
    while (1) {
        char *prev = p_end; //Stop condition

        read = (int) strtol(p_end, &p_end, 10);
        if (errno != ERANGE && prev != p_end) {
            tmp_arr[size++] = read;
        } else break;
    }

    *arr_len = size;

    /* Copying the array */
    *arr = malloc(sizeof(int) * size);

    memcpy(*arr, tmp_arr, sizeof(int) * size);
}


void prepare_input(
        FILE *file,
        int *res_c, int *proc_c,
        int **existing, int **available,
        int ***cur_allocation, int ***req
) {
    char *s;

    read_str(file, &s);
    parse_str(s, existing, res_c);

    read_str(file, &s);
    parse_str(s, available, res_c);

    /* Ignore empty line */
    read_str(file, &s);

    /* Read current allocation matrix */
    *proc_c = 0;
    int matrix_size = DEFAULT_PROC_CNT;
    *cur_allocation = malloc(sizeof(int *) * matrix_size);

    read_str(file, &s);
    while (strcmp("\n", s) != 0) {

        if (*proc_c == matrix_size) {
            matrix_size *= 2;
            *cur_allocation = realloc(*cur_allocation, sizeof(int *) * matrix_size);
        }

        parse_str(s, (*cur_allocation + *proc_c), res_c);
        (*proc_c)++;

        read_str(file, &s);
    }

    printf("Allocation matrix size: %d×%d\n\n", *proc_c, *res_c);

    /* Read request matrix */
    *req = malloc(sizeof(int *) * *proc_c);

    for (int i = 0; i < *proc_c; i++) {
        read_str(file, &s);
        parse_str(s, (*req + i), res_c);
    }
}