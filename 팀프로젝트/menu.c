#include "main.h"
#define MENUSIZE 5
#define STARTX 31
#define STARTY 25
#define TITLEX 16
#define TITLEY 10



char menuList[MENUSIZE][50] = { "1. 새 메 모","2. 메 모 열 기","3. 도 움 말","4. 옵 션", "5. 종 료" };
void clear_stdin() {
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n') {};
}

//방향키 선택 
int keyControl() {
	char temp = _getch();
  	if (temp == -32)
	{
		temp = _getch();
		switch (temp) {
		case 72:
			return UP;
			break;
		case 80:
			return DOWN;
			break;
		}
	}
	else if (temp == '\r') return SUBMIT;
	return -1;
}


//타이틀을 표시하는 부분 
void titleDraw() {
	gotoxy(TITLEX, TITLEY);
	printf("         #  #      ######      #####  #\n");
	gotoxy(TITLEX, TITLEY+1);
	printf("   ####  #  #      #    #        #    ####\n");
	gotoxy(TITLEX, TITLEY+2);
	printf("   #  # ##  #      ######       # #   #\n");
	gotoxy(TITLEX, TITLEY+3);
	printf("   ####  #  #         #            ###\n");
	gotoxy(TITLEX, TITLEY+4);
	printf("         #  #      ########       #   #\n");
	gotoxy(TITLEX, TITLEY+5);
	printf("                                   ###\n");
}


int menuDraw() {
	int x = STARTX;
	int y = STARTY;
	gotoxy(x - 2, y);
	printf("> %s", menuList[0]);
	for (int i = 1; i < MENUSIZE; i++) {
		gotoxy(x, y + i);
		printf("%s", menuList[i]);
	}
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP:
			if (y > STARTY) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		case DOWN:
			if (y < STARTY + MENUSIZE -1 ) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;

		case SUBMIT:
			clear_stdin();
			return y - STARTY;
		}
	}
}

int showAlert(char msg[]) {
	int input = 0;
	printf("\n%s \n", msg);
	printf("1. 예  / 2. 아니오 :  ");
	scanf("%d", &input);
	input = input == 1 ? true : false;
	return input;
}