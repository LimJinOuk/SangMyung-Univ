#include<stdio.h>

int main(void)
{
	int a;
	int b;
	int gcd;
	int gcd1;
	int min;
	int max;
	printf("첫번쨰 정수를 입력하시오.:");
	scanf("%d" , &a);

	printf("두번째 정수를 입력하시오.:");
	scanf("%d" , &b);

	for (int i = 1; i <= a && i <= b; ++i) 
	{
        	if (a % i == 0 && b % i == 0)
            		gcd = i;
	}

	for(int i=1; i <= a && i <= b; ++i)
    	{
        	if(a%i==0 && b%i==0)
            	gcd1 = i;
    	}
	
	max = gcd1;

    	min = (a * b) / gcd;


	printf("%d 와 %d의 최소공배수는 %d입니다.\n" , a , b, min);
	printf("%d와 %d의 최대공약수는 %d입니다.\n" , a , b , max);
	return 0;
}
