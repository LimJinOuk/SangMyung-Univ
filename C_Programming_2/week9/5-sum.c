#include<stdio.h>
#include<stdlib.h>

int main(int argc , char*argv[])
{
	int i;
	int result = 0;
	for(i = 1 ; i < argc ; i++)
	{
		int temp =atoi(argv[i]);
		result = result + temp;
	}

	printf("%d\n" , result);
	return 0;
}
