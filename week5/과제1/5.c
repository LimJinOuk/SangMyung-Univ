#include <stdio.h>

void printarr(int [] , int);
void shellsort(int [] , int);

int main(void)
{
	int a[] = {10 , 90 , 80 , 70 , 40 , 30 , 20 , 60 , 50};
	int n = sizeof(a) / sizeof(int);
	printarr(a , n);
	shellsort(a , n);
	printarr(a , n);

	return 0;
}

void shellsort(int v[] , int n)
{
	int gap , i , j , temp;

	for(gap = n/2; gap > 0 ; gap /=2)
		for(i = gap; i < n; i++)
			for(j = i - gap ; j >= 0 && v[j] > v[j+gap] ; j -= gap)
			{
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}

}

void printarr(int a[] , int b )
{
	int num0 = b - 1;
	int num = b - 1;
	int arr[num0];
	
	int i = 0;
	while(1)
	{
		int temp = a[i];
		arr[i] = temp;
		i = i + 1;
		if(i == b)
			break;
	}


	while(1)
	{
		printf("%d," , arr[num--]);
		if(num == 0)
		{
			printf("\n");
			break;
		}
	}
}
