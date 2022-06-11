#include "main.h"


void setTitle(char *title) {
	char *str = malloc(sizeof(char) * 100);
	sprintf(str, "title %s", title);
	system(str);
	free(str);
}


void initConsole() {
	system("mode con cols=80 lines=40");
	setTitle("�� �� ��");
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

//Ŀ���� ��Ÿ���� �ϰų� ���� �Լ� 
void OnOff(int bool) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = bool;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}
