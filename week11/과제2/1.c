#include<stdio.h>

//구조체 선언.
typedef struct A {
	int year;
	int month;
	int day;
}a;

typedef struct B {
	int year;
	int yearday;
}b;

typedef struct C {
	int pmonth;
	int pday;
}c;

//달 수 계산을 위한 daytab
static char daytab[2][13] = {
	{0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31},
	{0 , 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31}
};

int day_of_year(int year , int month , int day)
{
	int i , leap;
	//bool(0 , 1)값 leap에 저장.
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	//해당 년도의 일수 계산.
	for(i = 1; i < month ; i++){day += daytab[leap][i];}
	
	return day;
}
//구조체를 포인터로 받아 그 값을 온전히 전달.
int month_day(int year , int yearday , c *a)
{
	int i , leap;
	//bool(0,1)값을 leap에 저장.
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	//입력받은 yearday에서 달의 일수만큼 빼 가며 달이 몇번 있는지 , 마지막 남은 일수는 얼마인지 계산.
	for(i = 1 ; yearday > daytab[leap][i] ;i++)
	{
		yearday -= daytab[leap][i];
	}
	
	a->pmonth = i;
	a->pday = yearday;
}


int main(void)
{
	a a1 = {2024 , 5 , 24};
	a a2 = {2025 , 5 , 24};
	
	b b1 = {2024 , 200};
	b b2 = {2025 , 300};

	int day1 , day2;
	day1 = day_of_year(a1.year , a1.month , a1.day);
	day2 = day_of_year(a2.year , a2.month , a2.day);
	
	c c1;
	c c2;
	//위에 함수에서 구조체를 포인터로 받기에 주솟값을 전달.
	month_day(b1.year , b1.yearday , &c1);
	month_day(b2.year , b2.yearday , &c2);

	printf("2024년 5월 24일 -> 2024년 %d일\n" , day1);
	printf("2025년 5월 24일 -> 2025년 %d일\n" , day2);

	printf("2024년 200일 -> 2024년 %d월 %d일\n" ,c1.pmonth , c1.pday);
	printf("2025년 300일 -> 2025년 %d월 %d일\n" , c2.pmonth , c2.pday);

	return 0;
}

