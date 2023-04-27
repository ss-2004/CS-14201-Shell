#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <err.h>

int main(int argc, char *argv[]) {
    char buf;
    int sourcefile, destfile, n;
    sourcefile = open(argv[1], O_RDONLY);

    if (sourcefile == -1) {
        exit(0);
    } else {
        destfile = open(argv[2], O_WRONLY | O_CREAT, 0641);
        if (destfile == -1) {
            exit(0);
        } else {
            while ((n = read(sourcefile, &buf, 1)) != 0) {
                write(destfile, &buf, 1);
            }
            write(STDOUT_FILENO, "FILES COPIED\n", 15);
            close(sourcefile);
            close(destfile);
        }
    }

    return 0;
}