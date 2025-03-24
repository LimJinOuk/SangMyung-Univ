#include <stdio.h>

int main(void_)
{
	char am[] = "now is the time";
	char *pm = "now is the time";

	printf("am is %s , %p\n" , am , pm);
	printf("pm is %s , %p\n" , pm , pm);

	pm = "here i go";
	
	printf("am is %s\n" , am);
	printf("pm is %s , %p\n" , pm , pm);

	am[0] = 'x';
	printf("am is %s\n" , am);
}	
