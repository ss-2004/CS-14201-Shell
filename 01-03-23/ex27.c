#include <stdio.h>
#include <errno.h>

int main() {
    errno = 0;
    while (errno < ELAST) {
        errno++;
        perror("Error occurred ");
    }
    return 0;
}
