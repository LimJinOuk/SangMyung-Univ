#include <stdio.h>

/*check the num is even  or odd */
const char * is_bin (int num)
{
        int remain;
        remain = num % 2;
        /*checking algorithim*/
        if (remain == 0)
                return("num is even");
        else
                return("num is odd");

}

int main()
{
	int num;
        char * result;

        printf("enter the number that you want to chech this is odd or even :");
        scanf("%d" , &num);

        result = is_bin(num);
        printf("%s\n" , result);
        return 0;
}


