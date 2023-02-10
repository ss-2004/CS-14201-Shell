#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int id=fork();
    if(id == 0)
        printf("Child process Executing at ID : %d\n", id);
    else
        printf("Main process Executing at PID : %d\n", id);
    return 0;
}