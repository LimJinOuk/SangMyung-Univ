#include<stdio.h>
#include<string.h>

int count = 0;
int binsearch(int v[] , int x , int n)
{
	int index = -1;
	int num = 0;
	for(int i = 0 ; i <= n ; i++)
	{
		if(x == v[i]){index = i;}
		count = index;
	}

	if(index != -1)
	{
		return 1;
	}

	else{return -1;}
}

int main(void)
{
	int v[] = {10,20,30,40,50,60,70,80,90,100};
	int x;
	int n = sizeof(v) / sizeof(int);
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	printf("Enter key value.:");
	scanf("%d" , &x);
	int b = binsearch(v , x , n);
	int m = a[count];
	printf("%d\n" , count);
	if(b>= 0){printf("%d is v[%d] element.\n", x , m);}
	else{printf("no %d in v[]\n" , x);}

	return 0;

}

