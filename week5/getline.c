#include<stdio.h>

int get_line(char s[] , int lim)
{
	int c , i ;
	while(--lim > 0 && (c = getchar() != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
