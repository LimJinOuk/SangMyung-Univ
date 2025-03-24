#include <stdio.h>
#include<string.h>
#define maxindex 1000
#define maxlen 100
int alpha(char a)
{
	int ascii = (int)a;
	if((ascii < 91 && ascii > 64) || (ascii < 123 && ascii > 96 )){return 1;}
	else{return 0;}
}

long int * mid(int argc , char*argv[])
{
	int len = argc - 1;
	static long int* list[maxindex];

	for(int i = 0 ; i < len ; i++)
	{
		long int adr;
		adr = (long int)argv[1 + i];
		
		list[i] = adr;
	}
	
	return list;	
}


int main(int argc , char* argv[])
{
	int len = argc -1;
	for(int i = 0 ; i < len ; i ++){printf("%s\n" , mid(argc , argv)[i]);}
}
