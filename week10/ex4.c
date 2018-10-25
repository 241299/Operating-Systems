/**
 * Hard Link detector
 * @copyright Marsel Shayhin aka 241299
 * @date 25.10.2018
 */


#include <dirent.h>
#include <memory.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_HARD_LINKS 32

/**
 * Linked map structure and functions declaration
 */

typedef struct s_node {
    long unsigned key;
    char **value;
    int val_len;

    struct s_node *next;
} Node;

typedef struct s_linked_map {
    Node *head;
} Linked_Map;

Node *find_or_create(Linked_Map *map, long unsigned key);


/**
 * Output the results from the Map
 * @param map The Map to be traversed
 */

void output_results(Linked_Map *map);

/**
 * Main
 */

int main(int argc, char **argv) {

    /*
     * Directory stuff
     */

    const char *path = "./tmp";
    DIR *dirp;

    dirp = opendir(path);
    if (dirp == NULL) {
        fprintf(stderr, "Unable to access directory %s\n", path);
        exit(EXIT_FAILURE);
    }

    // Preparing Linked Map
    Linked_Map map = {.head = NULL};

    /*
     * Starting work
     */

    struct dirent *dep;
    struct stat *sbuf = malloc(sizeof(struct stat));


    // Search
    while ((dep = readdir(dirp)) != NULL) {

        // Path fix
        char *buf = malloc(strlen(path) + strlen(dep->d_name) + 2);
        strcpy(buf, path);
        strcat(buf, "/");
        strcat(buf, dep->d_name);

        stat(buf, sbuf);

        // Checking the number of hard links (we search for 1+)
        if (sbuf->st_nlink > 1) {
            Node *cur_node = find_or_create(&map, sbuf->st_ino);

            // Adding the file name to the list
            cur_node->value[cur_node->val_len] = strdup(dep->d_name);
            cur_node->val_len++;

            // TODO: Possible checking if MAX_HARD_LINKS exceeded
        }

        free(buf);
    }

    // Search done, freeing resources
    free(sbuf);
    closedir(dirp);

    // Outputting results
    output_results(&map);

    return 0;
}


/**
 * Creates a new Node
 * @param key The key
 * @return The pointer to the newly created Node
 */

Node *new_node(long unsigned key) {
    Node *n = malloc(sizeof(Node));
    n->key = key;
    n->next = NULL;
    n->val_len = 0;
    n->value = malloc(sizeof(char *) * MAX_HARD_LINKS);

    return n;
}


Node *find_or_create(Linked_Map *map, long unsigned key) {

    // Check whether the map is empty
    if (map->head == NULL) {
        map->head = new_node(key);
        return map->head;
    }

    /*
     * Search
     */

    Node *cur_node = map->head;

    while (1) {
        if (cur_node->key == key) return cur_node; // Found

        if (cur_node->next != NULL) cur_node = cur_node->next;
        else break; // Do not discard the last node, as it will be used
    }

    // Node was not found, create new
    cur_node->next = new_node(key);

    return cur_node->next;
}


void output_results(Linked_Map *map) {
    Node *cur_node = map->head;

    while (cur_node != NULL) {
        for (int i = 0; i < (cur_node->val_len - 1); i++) {
            printf("%s, ", cur_node->value[i]);
        }

        printf("%s\n", cur_node->value[cur_node->val_len - 1]);
        cur_node = cur_node->next;
    }
}