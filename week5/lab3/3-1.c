#include <stdio.h>

int main(void)
{
	int num1;
	int num2;
	int result;

	scanf("%d" , &num1);
	while((getchar()) != '\n'){}
	scanf("%d" , &num2);

	result = num1 - num2;
	
	if(result < 0)
	{
		result = -result;
	}
	printf("%d\n" , result);
	return 0;
}
