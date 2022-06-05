#include "main.h"
#define MENUSIZE 4
#define STARTX 31
#define STARTY 25
#define TITLEX 



char menuList[MENUSIZE][50] = { "1. 새 메 모","2. 메 모 열 기","3. 도 움 말","4. 종 료" };


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
	else if (temp == ' ') return SUBMIT;
}
//타이틀을 표시하는 부분 
void titleDraw() {

}


int menuDraw() {
	int x = STARTX;
	int y = STARTY;
	gotoxy(x - 2, y);
	printf("> %s", menuList[0]);
	for (int i = 1; i < 4; i++) {
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
			return y - STARTY;
		}
	}
}