#include <stdio.h>


int main(void)
{
    for(int n = 2 ; n < 301 ; n++)
    {
	    int i , j , cnt = 0;
    	for (i = 1; i <= n; i++)
    	{
        	if (n % i == 0)
            	cnt++;
    	}

    	if(cnt == 2)
	    	printf("%d\n" , n);
    }
    return 0;
}
