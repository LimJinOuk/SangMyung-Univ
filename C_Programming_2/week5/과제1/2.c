#include <stdio.h>

//반환값으로 문자열을 포인팅 하는 포인터를 반환하는 makebin함수.
char* makebin(unsigned int a)
{
	//변수 선언 remain의 값은 0 or 1 and share는 unsigned int에 2를 나눈 값이므로 int형 변수 선언. 
	// 이진수로 변환된 값을 담을 arry배열 선언.(static을 통해 그 값이 makebin이 종료되어도 사라지지 않게 함.) 
	// 이 때 unsigned int의 범위는 4,294,967,295이므로 2^32 -1 이기에, 배열의 크기를 null을 포함한 33자리로 구성.
	//4bytes int가 들어가기 위해 arry는 int형 배열로 선언.
	// arry에 원소에 접근하기 위한 변수 i선언.
	// arry의 주솟값을 포인팅하는 포인터 변수 rt선언
	int share;
	int remain;
	static int arry[33] = {0 ,};
	int i = 32;
	char * rt = &arry;
	//dec to bin algorithm.
	while(1)
	{
		share = a / 2;
		remain = a % 2;
		arry[i--] = remain;
		a = a / 2;
		if(a == 0)
			break;
	}
	arry[33] = '\0';

	return rt;
}


int main(void)
{
	unsigned int num;
	//makebin함수의 반환값을 받기 위한 포인터 변수 rt선언.
	int * rt;	
	scanf("%d" , &num);
	//makebin함수의 반환값을 받음.
	rt = makebin(num);
	//makebin의 반환값으로 받아온 배열의 원소를 출력.
	for(int i = 0; i <= 32 ; i++)
		printf("%d" , rt[i]);

	return 0;
}
