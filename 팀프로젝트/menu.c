#include "main.h"
#define MENUSIZE 4
#define STARTX 31
#define STARTY 25
#define TITLEX 



char menuList[MENUSIZE][50] = { "1. �� �� ��","2. �� �� �� ��","3. �� �� ��","4. �� ��" };


//����Ű ���� 
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
//Ÿ��Ʋ�� ǥ���ϴ� �κ� 
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