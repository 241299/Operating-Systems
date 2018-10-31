#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <memory.h>


/**
 * Function for opening files and reporting issues
 * @param filename The path to the file
 * @param mode The mode of opening the file
 * @see int open (const char *, int, ...)
 * @return The file descriptor in case of success.
 */

int fileopen(char* path, int mode) {
    int fd = open(path, mode, 0666);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    } else return fd;
}


int main() {

    /*
     * Opening the source and the destination files
     */

    int src_fd = fileopen("ex1.txt", O_RDONLY);
    int dest_fd = fileopen("ex1.memcpy.txt", O_RDWR | O_CREAT);

    /*
     * Getting the source file length
     */

    struct stat stat_s = {};
    if (fstat(src_fd, &stat_s)) {
        perror("fstat");
        exit(EXIT_FAILURE);
    };

    size_t src_len = (size_t) stat_s.st_size;


    // Truncating the destination file
    ftruncate(dest_fd, src_len);

    /*
     * Creating mmap for both src and dest
     */

    void *src_ad = mmap(NULL, src_len, PROT_READ, MAP_PRIVATE, src_fd, 0);

    void *dest_ad = mmap(NULL, src_len, PROT_READ | PROT_WRITE, MAP_SHARED, dest_fd, 0);

    /*
     * Copying the contents and closing
     */

    memcpy(dest_ad, src_ad, src_len);

    munmap(src_ad, src_len);
    munmap(dest_ad, src_len);

    close(src_fd);
    close(dest_fd);
}