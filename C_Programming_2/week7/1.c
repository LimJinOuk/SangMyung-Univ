#include <stdio.h>


int strlen(char *s)
{
	int n;
	for(n = 0; *s != '\0' ; s++)
		n++;
	return n;
}

int main(void)
{
	char str[] = "Hello there";
	int len = strlen(str);

	printf("%d\n" , len);
}
