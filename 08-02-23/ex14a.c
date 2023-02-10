#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readFile(char* filename)
{
	FILE *fp = fopen(filename, "r+");
	char ch;
	int c=0;

	if(fp == NULL) printf("File not found!");
	else
	{
		while ((ch = fgetc(fp)) != EOF) 
    	{
        	if(ch == ' ')
            	++c;
    	}
	}
	fclose(fp);
	return c;
}

int main(int argc, char** argv)
{
	printf("Spaces = %d\n", readFile(argv[1]));
	return 0;
}
