#include "key.h"
#define MENUSIZE 4
#define STARTX 24
#define STARTY 12



char menuList[MENUSIZE][50] = { "1. 새 메 모","2. 메 모 열 기","3. 도 움 말","4. 종 료" };

int keyControl() {
	char temp = getch();

	if (temp == 224)
	{
		temp = getch();
		switch (temp) {
		case 72:
			return UP;
			break;
		case 80:
			return DOWN;
			break;
		}


	if (temp == 'w' || temp == 'W') 
	else if (temp == 's' || temp == 'S') 
	else if (temp == ' ') return SUBMIT;
}
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