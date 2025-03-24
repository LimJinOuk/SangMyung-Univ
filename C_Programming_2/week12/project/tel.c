#include<ncurses.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<setjmp.h>
#include<unistd.h>

//점프 이벤트 스택을 저장할 점프 버프 생성.
jmp_buf restart;

//구조체 생성.
typedef struct List{
	char name[30];
	char phone[20];
	char memo[50];
}list;

void show(list** f , int line);
void search(list** f , int line);
void add(list** f , int line , FILE* fp);

int main(void)
{
	//재시작 지점 설정.
	setjmp(restart);

	//윈도우 초기화.
	initscr();
	start_color();
	//box설정 및 제목 설정.
        box(stdscr , '|' , '-');
        wprintw(stdscr , "Welcome to Phone Number Programm\n");

        //색상 설정.
        init_color(1 , 0 , 1000 , 0); //Green
        init_color(2 , 0 , 0 , 1000); //Blue
        init_color(3 , 1000 , 0 , 0); //Red

        //색상 pair 설정.
        init_pair(1 , 1 , 2); //blue w Green letters
        init_pair(2 , 1 , 3); //Red W Green letters

        //xy 최댓값 구하기.
        int yMax , xMax;
        getmaxyx(stdscr , yMax , xMax);

	//:기준으로 분리한 항목을 임시 저장할 공간 생성.
	char* name[1000];
	char* phone[1000];
	char* memo[1000];
	
	int num = 0;
	char tmp;

	//파일 읽어들이기.
	FILE* fp;
	fp = fopen("./data.txt" , "a+");
	
	//파일에 아무것도 없을 시 에러 표출.
	if(fp == NULL)
	{
		fprintf(stderr , "Error : There is no data.");
		exit(1);
	}

	//동적할당을 위해 파일의 개행문자 수 세기.
	while((tmp = fgetc(fp))!= EOF){if(tmp == '\n'){num++;}}
	
	//구조체 배열 생성 후 동적할당
	list* f[(int)num];	
	for(int i = 0 ; i < num ; i++){f[i] = (list*)calloc(num , sizeof(char*));}
	
	//파일 위치 지시자 초기화.
	int now = ftell(fp);
	int R = (-1)*now;
	int result = fseek(fp , R , SEEK_CUR );
	if(result != 0){printf("Error\n");}
	
	//파일을 한 줄씩 읽어 : 기준으로 분할.
	char line[1000];
	int i = 0;
	while(fgets(line , sizeof(line) , fp) != NULL)
	{
		//:기준으로 분리하기
		char* p;
		p = strtok(line , ":");
		name[i] = p;
		p = strtok(NULL , ":");
		phone[i] = p;
		p = strtok(NULL , ":");
		memo[i] = p;

		//분리한 항목 구조체에 대입		
		strcpy(f[i]->name , name[i]);
		strcpy(f[i]->phone , phone[i]);
		strcpy(f[i]->memo , memo[i]);
		i++;
		
	}
	i = 0;

	//menu창 생성.
	WINDOW* menu;
	menu = newwin(6 , xMax - 12 , yMax - 8 , 5);
	box(menu , 0 , 0);
	refresh();
	wrefresh(menu);

	//키보드 입력 활성.
	keypad(menu , true);
	
	wprintw(menu , "Select the Menu.(Use Right Arrow to enter the option)\n");

	//메뉴 드롭다운 리스트 생성.
	char* choices[5] = {"1.Search" , "2.Add" , "3.Delete" , "4.List" , "5.Exit"};
	int choice;
	int highlight = 0;
	//커서 하이라이트 설정 및 드롭다운 움직임 설정.
	while(1)
	{
		for(int i = 0; i < 5; i++)
		{
			if(i == highlight){wattron(menu , A_REVERSE);}
			mvwprintw(menu , i + 1 , 1 , choices[i]);
			wattroff(menu , A_REVERSE);
		}
		choice = wgetch(menu);

		switch(choice)
		{
			case KEY_UP:
				highlight--;
				if(highlight == -1){highlight = 0;}
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight == 5){highlight = 4;}
				break;
			default:
				break;
		}
		if(choice == KEY_RIGHT){break;}
	}

	printw("Your choice was : %s\n" , choices[highlight]);
	refresh();
	wrefresh(menu);

	//옵션에 따라 행동 설정.
	switch(highlight)
	{
		case 4: // exit
			endwin();
			break;
		case 0: // search
			search(f , num);
			break;
		case 1: // add
			add(f , num , fp);
			break;
		case 2: // delete
			break;
		case 3: // list
			show(f , num);
			break;
	}

	//파일 닫기.
	fclose(fp);

	//동적할당 해제.
        if(*f != NULL){free(*f);}


}

/*
void delete(list** f , int line)
{}
*/

void add(list** f , int line , FILE* fp)
{
	char name[10000];
	char phone[1000];
	char memo[1000];

	//xy 최댓값 구하기.
        int yMax , xMax;
        getmaxyx(stdscr , yMax , xMax);

        //화면을 지움.
        erase();
        refresh();

        //메뉴 창 생성.
        WINDOW* add;
        add = newwin(6 , xMax - 12 , yMax - 8 , 5);
        box(add , 0 , 0);
        refresh();
        wrefresh(add);
	//사용자 입력
	wprintw(add , "enter name: ");
	wscanw(add , "%s" , name);

	wprintw(add , "enter phone: ");
	wscanw(add , "%s" , phone);

	wprintw(add , "enter memo: ");
	wscanw(add , "%s" , memo);

	refresh();
	wrefresh(add);
	//사용자 입력 정렬
	strcat(name , ":");
	strcat(name , phone);
	strcat(name , ":");
	strcat(name , memo);
	strcat(name , "\n");

	//검수
	int result;
	refresh();
	wrefresh(add);

	result = fputs(name , fp);
	if(result>= 0){wprintw(add , "Add Success!\n ");}
	else if(result < 0){wprintw(add , "Add Faile.\n");}
	else if(result == EOF){wprintw(add , "There is Error.\n");}
	refresh();
	wrefresh(add);

	while(1)
	{
		wprintw(add , "You want to EXIT?(Y/N) :");
		wrefresh(add);
		char an = wgetch(add);
		wprintw(add , "\n");
		wrefresh(add);

		if(an == 89|| an ==121) // Y
		{
			endwin();
			touchwin(stdscr);
			refresh();
			endwin();
			break;
		}
		else if(an == 78 || an == 110) //N
		{
			wprintw(add , "You want to back to main menu?(Y/N) : ");
			wrefresh(add);
			char a = wgetch(add);
			wprintw(add , "\n");
			wrefresh(add);
			if(a == 89 || a == 121) //Y
			{clear();longjmp(restart , 0);break;}
		}
	}
}


void show(list** f, int line)
{
	//xy 최댓값 구하기
	int yMax , xMax;
	getmaxyx(stdscr , yMax , xMax);

	//화면 지우기
	erase();
	refresh();

	//새 창 생성.
	WINDOW* show = newwin(200 , xMax - 12 , yMax - 35 , 5);
	box(show , 0 , 0);
	refresh();
	wrefresh(show);

	//메세지 출력.
	wprintw(show , "You chose list option\n");
	wprintw(show , "Here is the list\n");
	for(int i = 0 ; i < line ; i++)
	{
		wprintw(show , "No.%d. " , i + 1);
		wprintw(show , "Name: %s " , f[i]->name );
		wprintw(show , "Phone: %s " , f[i]->phone );
		wprintw(show , "Memo:%s\n" , f[i]->memo );
	}

	while(1)
	{
		wprintw(show , "You want to EXIT?(y/N) :");
		refresh();
		wrefresh(show);
		char an = wgetch(show);
		wprintw(show , "\n");

		//프로그램 종료.
		if(an == 89 || an == 121)
		{
			endwin();
			touchwin(stdscr);
			wrefresh(stdscr);
			refresh();
			wrefresh(show);
			endwin();
			break;
		}
		else if(an == 78 || an == 110)
		{
			wprintw(show , "You want to back to the main menu?(Y/N):");
			refresh();
			wrefresh(show);
			char a = wgetch(show);
			wprintw(show , "\n");
			if(a == 89 || a == 121){clear();longjmp(restart , 0);break;}
		}
		else
		{
			wprintw(show , "\n");
			wprintw(show ,"You enter wrong character. Retry it.\n");
			wprintw(show, "Please wait...\n");
			wrefresh(show);
			refresh();
			sleep(1);
			refresh();
			wrefresh(show);
		}

	}
}

//search 함수 메서드.
void search(list** f ,int line)
{
	//xy 최댓값 구하기.
        int yMax , xMax;
        getmaxyx(stdscr , yMax , xMax);

	//화면을 지움.
	erase();
	refresh();

	//메뉴 창 생성.
	WINDOW* search_menu;
	search_menu = newwin(6 , xMax - 12 , yMax - 8 , 5);
	box(search_menu , 0 , 0);
	refresh();
	wrefresh(search_menu);

	//키보드 입력 활성.
	keypad(search_menu , true);

	wprintw(search_menu , "Select the Menu(Use Right Arrow to enter the Option.\n");

	//드롭다운 메뉴 생성.
	char* choices[3] = {"1.Name" , "2.Phone" , "3.Memo"};
	int choice;
	int highlight = 0;

	//커서 하이라이트 설정 및 드롭다운 움직임 설정.
	while(1)
	{
		for(int i = 0 ; i < 3 ; i++)
		{
			if(i == highlight){wattron(search_menu , A_REVERSE);}
			mvwprintw(search_menu , i + 1 , 1 , choices[i]);
			wattroff(search_menu , A_REVERSE);
		}
		choice = wgetch(search_menu);

		switch(choice)
		{
			case KEY_UP:
				highlight--;
				if(highlight == -1){highlight = 0;}
				break;
			case KEY_DOWN:
				highlight++;
				if(highlight == 3){highlight = 2;}
				break;
			default:
				break;
		}
		if(choice == KEY_RIGHT){break;}
	}

	//화면을 지움.
	erase();

	wprintw(stdscr, "choice was: %s\n" , choices[highlight]);

	refresh();
	wrefresh(search_menu);

	char name[30];
	char phone[20];
	char memo[50];

	switch(highlight)
	{
		case 0: //name
			printw("You Chose option for name.\n");
			printw("Enter the name to search\n");
			scanw("%s" , name);	
			//구조체에 입력된 내용이 있는지 확인.
			for(int i = 0 ; i < line ; i++)
			{	
				if(strcmp(name , f[i]->name) == 0)
				{
					printw("There is name that you searched!\n");
					printw("Name is %s , Phone is %s , Memo is %s\n" , f[i]->name , f[i]->phone , f[i]->memo);
				refresh();
				wrefresh(search_menu);
				break;
				}
				if(i == line - 1)
				{
					printw("There is no data.\n");
					refresh();
					wrefresh(search_menu);
				}
			}
			break;
		case 1: //phone
			printw("You chose option for phone.\n");
			printw("Enter the number to search\n");
			scanw("%s" , phone);
			//구조체에 입력된 내용이 있는지 확인.
                        for(int i = 0 ; i < line ; i++)
                        {
                                if(strcmp(phone , f[i]->phone) == 0)
                                {
                                        printw("There is name that you searched!\n");
                                        printw("Name is %s , Phone is %s , Memo is %s\n" , f[i]->name , f[i]->phone , f[i]->memo);
                                refresh();
                                wrefresh(search_menu);
                                break;
                                }
                                if(i == line - 1)
                                {
                                        printw("There is no data.\n");
                                        refresh();
                                        wrefresh(search_menu);
                                }
                        }

			break;
		case 2: //memo
			printw("You chose option for memo\n");
			printw("Enter the memo to search\n");
			scanw("%s" , memo);
			//구조체에 입력된 내용이 있는지 확인.
                        for(int i = 0 ; i < line ; i++)
                        {
                                if(strcmp(memo , f[i]->memo) == 0)
                                {
                                        printw("There is name that you searched!\n");
                                        printw("Name is %s , Phone is %s , Memo is %s\n" , f[i]->name , f[i]->phone , f[i]->memo);
                                refresh();
                                wrefresh(search_menu);
                                break;
                                }
                                if(i == line - 1)
                                {
                                        printw("There is no data.\n");
                                        refresh();
                                        wrefresh(search_menu);
                                }
                        }

			break;
	}

	while(1)
	{
		printw("You want to EXIT?(Y/N) :");
		wrefresh(search_menu);
		refresh();
		char an = wgetch(stdscr);
		printw("\n");
		refresh();
		if(an == 89 || an == 121 ) // Y
		{
			endwin();
			touchwin(stdscr);
			refresh();
			wrefresh(search_menu);	
			endwin();
			break;
		}
		else if(an == 78 || an == 110) //N
		{
			printw("You want to back to the main menu?(Y/N): ");
			refresh();
			char a = wgetch(stdscr);
			printw("\n");
			refresh();

			if(a == 89 || a == 121)
			{clear();longjmp(restart , 0);break;}
		}
		
	}

}
