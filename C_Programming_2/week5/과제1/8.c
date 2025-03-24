#include <stdio.h>

int binarysearch(int x , int v[] , int n)
{
	int low , high , mid;

	low = 0;
	high = n - 1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else if (x >v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1; 
}

int main(void)
{
	int v[] = {10 , 20 , 30 , 40 , 50 , 60 , 70 , 80 , 90 , 100};
	int x;
	int m;
	int n = sizeof(v) / sizeof(int);

	printf("Enter key value: ");
	scanf("%d" , &x);

	if((binarysearch(x , v , n)) >= 0)
		printf("%d is v[%d] element.\n" , x, m);
	else
		printf("no %d in v[]. \n" ,x);

	return 0;
}
