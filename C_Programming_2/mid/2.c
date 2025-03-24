#include <stdio.h>

int factorial(int n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}

int main (void)
{
	for(int i = 1 ; i < 16 ; i ++)
	{
		printf("%d! = %lld\n" ,i , factorial(i));
	}

}

