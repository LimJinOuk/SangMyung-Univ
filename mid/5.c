#include <stdio.h>
#include<string.h>

void writelines(char*[] , int);
void qsort(char*[] , int , int);
void swap(char*[] , int , int);

int main()
{
	char* a[] = {"banana" , "kiwi" , "grape" , "apple" , "cherry"};
	int n = sizeof(a) / sizeof(char*);
	
	printf("\nBefore sort.\n");
	writelines(a , n);

	qsort(a , 0 , n-1);

	printf("\nAfter sort.\n");
	writelines(a , n);

	return 0;
}

int cpmpare(const char * a , const char* b)
{
	return strcmp(a , b);
}

void writelines(char*a[] , int len)
{
	for(int i = 0 ; i < len ; i++){printf("%s\n" , a[i]);}
}

void swap(char*arr[] , int a, int b)
{
	char * temp;
	arr[a] = temp;
	arr[a] = arr[b];
	arr[b] = temp;

}

void qsort(char*a[] , int n , int b)
{
	for(int i = 1; i < n; i++)
	{
		char* key = a[i];

		int j = i - 1;
	
		while(j >= 0 && cpmpare(a[j] , key) > 0)
		{
			swap(a , j , j +1);
		}

		a[j+1] = key;
	}	
}
