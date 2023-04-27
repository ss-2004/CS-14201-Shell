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

int dir_select(struct direct *entry) {
    if (entry->d_type == DT_DIR && strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, ".") != 0)
        return (TRUE);
    else
        return (FALSE);
}

int main() {
    int count, i;
    struct dirent **dirs;
    int dir_select();

    if (getwd(pathname) == NULL) {
        printf("Error getting path\n");
        exit(0);
    }

    printf("Current Working Directory = %s\n", pathname);
    count = scandir(pathname, &dirs, dir_select, alphasort);
    if (count <= 0) {
        printf("No subdirs in this dir\n");
        exit(0);
    }

    printf("Number of dir = %d\n", count - 1);
    for (i = 1; i < count; i++)
        printf("%s  \n", dirs[i]->d_name);
    return 0;
}
