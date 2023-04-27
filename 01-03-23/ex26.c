#include<stdio.h>
#include<stdlib.h>

void writeFile(char data, char *dest) {
    FILE *fp;
    int i = 0;
    fp = fopen(dest, "a+");
    if (fp == NULL) {
        printf("ERROR\n");
        return;
    } else {
        fprintf(fp, "%c", data);
    }
    fprintf(fp, "%c", "\n");
    fclose(fp);
}

void readFile(char *source, char *dest) {
    FILE *fp;
    int ft, i = 0;
    fp = fopen(source, "r+");
    if (fp == NULL) {
        printf("ERROR\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    ft = ftell(fp);
    while (i < ft) {
        i++;
        fseek(fp, -i, SEEK_END);
        writeFile(fgetc(fp), dest);
    }
    fclose(fp);
}

int main(int argc, char **argv) {
    readFile(argv[1], argv[2]);
    return 0;
}