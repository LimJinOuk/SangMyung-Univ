#include <stdio.h>

int main(void)
{
	char hexadecimal[200] = {0,};
  	int input;
	int position = 0;
	while(scanf("%d" , &input) != EOF)
	{	
		while (1)
		{
        		int mod = input % 16;    // 16으로 나누었을 때 나머지를 구함
        		if (mod < 10) // 나머지가 10보다 작으면
        		{
            			// 숫자 0의 ASCII 코드 값 48 + 나머지
            			hexadecimal[position] = 48 + mod;
        		}
        		else    	// 나머지가 10보다 크거나 같으면
        		{
            			// 나머지에서 10을 뺀 값과 영문 대문자 A의 ASCII 코드 값 65를 더함
            			hexadecimal[position] = 65 + (mod - 10);
        			

        			input = input / 16;    // 16으로 나눈 몫을 저장

        			position++;    // 자릿수 변경

        			if (input == 0)    // 몫이 0이되면 반복을 끝냄
            				break;
    			}
		}
	}
	for (int i = position - 1; i >= 0; i--)
    	{
        	printf("%c", hexadecimal[i]);
    	}

    	printf("\n");
	return 0;
}
