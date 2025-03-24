#include <stdio.h>

int factorial(int n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}

int main (void)
{
	for(int i = 1 ; i < 21 ; i ++)
	{
		printf("%lld\n" , factorial(i));
	}

}


