#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(char* filename, char mode)
{
    FILE *fp = fopen(filename, "r+");
    char ch;
    int wc=0, lc=0, sp=0;

    if(fp == NULL) printf("File not found!");
    else
    {
     	while ((ch = fgetc(fp)) != EOF) 
        {
            lc++;
			if(ch == ' ')
                sp++;
        }
    }
	wc=sp+lc;
    fclose(fp);

	switch(mode)
	{
		case 'w':
			printf("Words = %d\n", wc);
			break;
		case 'l':
			printf("Lines = %d\n", lc);
			break;
		case 's':
			printf("Spaces = %d\n", sp);
			break;
		default :
			printf("%c is an Invalid Choice\n", mode);
	}
}

int main(int argc, char** argv)
{
	char fp[128];
	char op;
	printf("Enter file path : ");
	scanf("%*[^\n]%*c", &fp);
	printf("Enter w for word count\nEnter l for line count\nEnter s for space count\n");
	scanf("%c", &op);
    readFile(fp, op);
    return 0;
}

