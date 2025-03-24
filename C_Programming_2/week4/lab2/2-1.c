/*header import*/
#include <stdio.h>

/*convert fahrenheit to clsius*/
int main(void)
{
	/*variables declararion*/
	float far ,cel;
	int lower , upper , step;

	/*set limit of values*/
	lower = 0;
	upper = 200;
	step = 20;
	
	/*initializing far value*/
	far = lower;
	
	/*print the name of value*/
	printf("fahrenheit\t");
	printf("celsius\n");

	while(far <= upper)
	{
		/*calc and convert fahrenheit to celsius*/
		cel = (5.0 / 9.0) * (far - 32.0);
		/*print the result with format*/
		printf("%.6f\t%.6f \n" , far , cel);
		/*add value of step to far*/
		far = far + step;
	}
	
	return 0;

}
