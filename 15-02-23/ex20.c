#include <stdio.h>
#include <time.h>

void printTime()
{
	time_t s, val = 1;
    struct tm* curr_time;
    s = time(NULL); 
    curr_time = localtime(&s); 
    printf("%02d:%02d:%02d\n", curr_time->tm_hour, curr_time->tm_min, curr_time->tm_sec);

}

int main() {
	for(;;)
	{
		printTime();
		sleep(60);
	}

}
