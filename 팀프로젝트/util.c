#include "main.h"


void init() {
	system("mode con cols=80 lines=40 | title �� �� ��");
	OnOff(0);
}


int loadFileList() {
	FILE* fp = fopen("fileList.txt", "rb");
	if (fp == NULL) {
		printf("���� �ۼ��� ������ �����ϴ�");
		return NULL;
	}



}
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void OnOff(int bool) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = bool;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
