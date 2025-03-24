#include <stdio.h>
#include <limits.h>

int main(void)
{
	//limits.h에 들어있는 매크로를 호출하여 사용.
	signed char signed_char_max = CHAR_MAX;
	signed char signed_char_min = CHAR_MIN;

	unsigned char unsigned_char_max = UCHAR_MAX;
	unsigned char unsigned_char_min = 0;

	signed short signed_short_max = SHRT_MAX;
	signed short signed_short_min = SHRT_MIN;

	unsigned short un_short_max = USHRT_MAX;
	unsigned short un_short_min = 0;

	signed int s_int_max = INT_MAX;
	signed int s_int_min = INT_MIN;

	unsigned int u_int_max = UINT_MAX;
	unsigned int u_int_min = 0;

	signed int s_long_max = LONG_MAX;
	signed int s_long_min = LONG_MIN;

	unsigned long u_long_max = ULONG_MAX;
	unsigned long u_long_min = 0;
//si pass
	printf("signed int 의 최댓값과 최솟값은 각각 %d와%d입니다.\n", s_int_max , s_int_min);
//usi pass
	printf("unsigned int의 최댓값과 최솟값은 각각 %ld와  %ld입니다. \n" , u_int_max , u_int_min);
//uc pass
	printf("signed char의 최댓값과 최솟값은 각각 %d와 %d입니다.\n", signed_char_max , signed_char_min);
//usc pass
	printf("unsigned char의 최댓값과 최솟값은 각각 %ld와 %ld입니다.\n" , unsigned_char_max , unsigned_char_min);
//ss pass
	printf("sigend short의 최댓값과 최솟값은 각각 %ld 와 %d입니다.\n" , signed_short_max , signed_short_min);
//uss pass
	printf("unsigned short의 최댓값과 최솟값은 각각 %ld와  %ld입니다. \n" , un_short_max , un_short_min);

	printf("signed long의 최댓값과 최솟값은 각각 %ld와 %ld입니다. \n" , s_long_max , s_long_min);

	printf("unsigned long의 최댓값과 최솟값은 각각 %ld와 %ld입니다.\n" , u_long_max , u_long_min);

	return 0;
}
