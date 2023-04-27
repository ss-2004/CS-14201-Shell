#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <utime.h>
#include <fcntl.h>

void print_perms(mode_t perms) {
    printf((perms & S_IRUSR) ? "r" : "-");
    printf((perms & S_IWUSR) ? "w" : "-");
    printf((perms & S_IXUSR) ? "x" : "-");
    printf((perms & S_IRGRP) ? "r" : "-");
    printf((perms & S_IWGRP) ? "w" : "-");
    printf((perms & S_IXGRP) ? "x" : "-");
    printf((perms & S_IROTH) ? "r" : "-");
    printf((perms & S_IWOTH) ? "w" : "-");
    printf((perms & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main(int argc, char *argv[]) {
    struct dirent *myFile;
    struct stat info;
    stat(argv[1], &info);
    DIR *dir = opendir(argv[1]);

    if (dir) {
        while ((myFile = readdir(dir))) {
            printf("%s\n", myFile->d_name);
            printf("Type : ");
            print_perms(info.st_mode);
            printf("Links : %4d\n", info.st_nlink);
            printf("Last access : %s\n", ctime(&info.st_atimespec));
        }
    }
    closedir(dir);
    return 0;
}