#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_LEN (1<<16) + 1 // 65536 bytes null-terminated
#define APPEND_FLAG "-a"
#define mode(flag) (flag ? "a" : "w")


/**
 * Takes the data from stdin and outputs it to stdout and specified files
 * @param argc The count of the arguments from argv to be processed
 * @param argv The arguments array. When <code>argc > 1</code>, the <code>argv[1]</code> may be either <code>-a</code> flag
 *          or the file for output, all succeeding arguments specify files for output
 * @return 0 in case of success, -1 and message in `stderr` otherwise
 */

int main(int argc, char **argv) {
    /* Reading input */
    char in[MAX_LEN];
    fread(in, 1, MAX_LEN, stdin);
    ferror(stdin);

    /* Defining outputs */
    FILE **out = malloc(argc * sizeof(FILE *));

    /* Putting stdout to be output to, as in specifications */
    *out = stdout;

    /*
     * Adding arguments to be output to
     * Searching for -a flag as the first argument
     */
    short flag = 0;

    for (int i = 1; i < argc; i++) {
        if (i == 1 && !strcmp(APPEND_FLAG, argv[i])) {
            flag = 1;
            out[i] = NULL;
        } else out[i] = fopen(argv[i], mode(flag));
    }

    /* Outputting file by file */
    for (int i = 0; i < argc; i++) {
        if (out[i]) {
            fputs(in, out[i]);
            fclose(out[i]);
        }
    }
}