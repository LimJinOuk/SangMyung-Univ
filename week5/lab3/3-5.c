#include<stdio.h>
int prime(int a)
{
	/*2,3,5,7*/
	if(a == 2 || a == 3 || a == 5 || a == 7 )
		return 1;
	else if(a > 10 &&(a % 2 != 2 && a % 3 != 0 && a % 5 != 0 && a % 7 != 0))
		return 1;
	else
		return 0;
}

int main(void)
{	
	int i = 1;
	while(1)
	{
		if(prime(i) == 1)
			printf("%d is prime num\n" , i);
		else
			printf("%d is not prime num\n" , i);
		i++;
		if(i == 201)
			break;
	}
}
