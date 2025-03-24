#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//qsort함수 사용을 위한 compare 함수
int compare(const int* a, const int* b) {
	return(*a - *b);
}

int main(int argc , char** argv)
{
	//argv를 int형 배열로 변환
	int clist[100] = {};
	for(int i = 0 ; i<argc - 1 ; i++){clist[i] = atoi(argv[i+1]);}
	
	//-a옵션 확인
	if(strcmp(argv[1] , "-a") == 0)
	{
		//-a문자 제거를 위한 새로운 배열 생성
		int olist[100] = {};
		for(int i = 0 ; i <argc -2; i++)
		{
			olist[i] = clist[i+1];
		}
		//qsort진행
		qsort(olist , argc - 2 , sizeof(int) , compare);
		//출력
		for(int i = 0 ; i < argc -2 ; i++)
		{
			printf("%d " , clist[i+1]);
		}
		printf("\n");
	}
	else
	{
		//qsort진행
		qsort(clist , argc - 1 , sizeof(int) , compare);
		//출력
		for(int i = 0 ; i <argc - 1; i++)
		{
			printf("%d " , clist[i]);
		}
		printf("\n");
	}

}
