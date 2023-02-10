// ls UNIX

#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FALSE 0
#define TRUE 1

extern int alphasort();

char pathname[MAXPATHLEN];

int file_select(struct direct *entry) {
    if ((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
        return (FALSE);
    else
        return (TRUE);
}

int main() {
    int count, i;
    struct dirent **files;
    int file_select();

    if (getwd(pathname) == NULL) {
        printf("Error getting path\n");
        exit(0);
    }

    printf("Current Working Directory = %s\n", pathname);
    count = scandir(pathname, &files, file_select, alphasort);
    if (count <= 0) {
        printf("No files in this directory\n");
        exit(0);
    }

    printf("Number of files = %d\n", count);
    for (i = 1; i < count - 1; i++)
        printf("%s  \n", files[i - 1]->d_name);
    return 0;
}

