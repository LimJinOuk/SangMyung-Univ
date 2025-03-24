#include <stdio.h>

long long fac(int a)
{
	long long result = 1;

	for(int term = 1; term <= a; term ++)
	{
		result = result * term;
	}

	return result;
}

int main(void)
{
	for(int a = 1 ; a <= 20 ; a++)
	{
		long long r;
		r = fac(a);
		printf("%lld\n" , r);
	}
	return 0;
}
