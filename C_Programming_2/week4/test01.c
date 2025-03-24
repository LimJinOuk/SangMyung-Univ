#include <stdio.h>
int num;

/*check the num is even  or odd */
const char * is_bin ()
{
        int remain;
        remain = num % 2;
	printf("%d\n" , num);
       	/*checking algorithim*/
        if (remain == 0)
                return("%d is even" , num);
        else
                return("%d is odd" , num);

}

int main()
{
        char * result;

        printf("enter the number that you want to chech this is odd or even :");
        scanf("%d" , &num);

        result = is_bin();
        printf("%s\n" , result);
        return 0;
}


