#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int fd[2];
    if (pipe(fd) == -1) return 1;

    int pid1 = fork();
    if (pid1 < 0)return 2;
    if (pid1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
//        execlp("ping", "ping", "-c", "5", "google.com", NULL);
        execlp("cat", "cat", argv[1], NULL);
    }

    int pid2 = fork();
    if (pid2 < 0)return 3;
    if (pid2 == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
//        execlp("grep", "grep", "rtt", NULL);
        execlp("grep", "grep", argv[2], NULL);
    }

    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}