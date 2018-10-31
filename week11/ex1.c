#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <memory.h>

const char s[] = "This is a nice day";

int main() {

    /*
     * Opening the file
     */

    int fd = open("ex1.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    };


    // Truncating the file
    ftruncate(fd, sizeof(s));

    /*
     * Creating mmap
     */

    struct stat stat_s = {};
    if (fstat(fd, &stat_s)) {
        perror("fstat");
        exit(EXIT_FAILURE);
    };

    size_t len = (size_t) stat_s.st_size;

    void *ad = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);


    /*
     * Copying the contents and closing
     */

    memcpy(ad, s, sizeof(s));

    munmap(ad, sizeof(s));
    close(fd);
}