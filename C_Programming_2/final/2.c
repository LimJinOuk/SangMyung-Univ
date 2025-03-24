#include<stdio.h>
#include<string.h>
typedef struct
{
	char name[30];
	float n1[50];
	int n2[50];
}price;

int main(void)
{
	char line[255];
	char* name[1000];
	float* n1[1000];
	int* n2[1000];

	FILE* fp = fopen("./2.txt" , "r");

	price* f[5];
	int i = 0;
	while (fgets(line, sizeof(line), fp) != NULL ) 
	{
		char* p;
		//,기준으로 분리.
		p = strtok(line , ",");
		printf("%s\n" , p);
		name[i] = p;
		p = strtok(NULL , ",");
		n1[i] =(float*)p;
		p = strtok(NULL , ",");
		n2[i] =(int*)p;
		

		//분리한 항목 대입.
		strcpy(f[i]->name , name[i]);
		i++;
	}
}
