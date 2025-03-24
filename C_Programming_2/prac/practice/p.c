#include <stdio.h>
#include <string.h>
#define maxlen 100

long int * sort(int argc , char* argv[])
{
	static long int arr[maxlen];
	
	for(int i = 1; i <= argc - 1 ; i ++)
	{
		arr[i] = (long int)argv[i];
	}

	char b[maxlen];
	int o = 1;
	for(int i = 0 ; i <argc - 1; i++)
	{
		b[i] = (char)arr[o++];
	}

	int len = strlen(b);

	for(int i = 0 ; i < len ; i++)
	{
		
	}	
	return arr;
}


int main(int argc ,char* argv[])
{
	long int result[argc - 1];
	
	for(int i = 1 ; i <= argc - 1; i++){result[i] = sort(argc , argv)[i];}

	for(int i = 1 ; i <= argc - 1; i++){printf("%s\n" , result[i]);}

}

