#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int readFile(char *filename) {
    char str;
    int c = 0;
    int fd = open(filename, O_RDONLY);

    if (fd) {
        while (read(fd, &str, 1) == 1) {
            if (str == ' ')
                ++c;
        }
    } else printf("File not found!");

    close(fd);
    return c;
}

int main(int argc, char **argv) {
    printf("Spaces = %d\n", readFile(argv[1]));
    return 0;
}
