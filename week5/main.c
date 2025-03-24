#include<stdio.h>
#define maxline 1000

int get_line(char line[] , int max);
int strindex(char spurce[] , char searchfor[]);

char pattern[] = "ould";

int main(void)
{
	char line[maxline];
	int found = 0;

	while(get_line(line , maxline) > 0)
		if(strindex(line , pattern) >= 0)
		{
			printf("%s\n" , line);
			found++;
		}
	return found;
}
