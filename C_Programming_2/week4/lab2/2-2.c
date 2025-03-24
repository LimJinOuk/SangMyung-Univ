/*headers import*/
#include<stdio.h>

/*define macros*/
#define max 64

/*convert entered line to each words*/

int main()
{
	char enter[max];
	char term;
	int i = 0;
	char result[max];

	while(1)
	{
		term = getchar();
		if(term == EOF)
		{	
			enter[i] = '\0';
			break;
		}
		else if(term != EOF)
		{
			enter[i] = term;
			i++;
		}
	}
	
	while(1)
	{
		char res[max];
		char result[max];
		char t[100];
		int k = 0;

		for(int o = 0; o<= max; o++)
		{
			char key = enter[o];
			if(key == ' ')
			{
				t[k] = o;
				k++;			
			}
		}
		
	}	

	return 0;
}
