#include<stdio.h>
#include<math.h>

int main(int argc , char* argv[])
{
	float sum;
	float avg;
	float std;
	float temp = 0;

	for(int i = 1 ; i < argc; i++)
	{
		temp = temp + (int)argv[i];
	}
	//합 계산
	sum = temp;

	//평균 계산
	avg = (float)sum / (argc - 1);
	double var;
	//분산 계산.
	for(int i = 0; i < argc ; i++){var += (((int)argv[i]-avg)*((int)argv[i]-avg)); }
	var = var/(argc - 1);

	//표준편차 계산.
	std = sqrt(var);

	printf("%f\n" , sum);
	printf("%f\n" , avg);
	printf("%f\n" , std);

}
