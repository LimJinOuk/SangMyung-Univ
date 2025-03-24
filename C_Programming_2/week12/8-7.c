#include<stdio.h>
#include<unistd.h>
#define BUFSIZE 100
main()
{
	char buff[BUFSIZE];
	int n;
	
	while((n = read(0, buff , BUFSIZE)) > 0)
		write(1 , buff , n);
	return 0;
}
