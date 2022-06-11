#include "main.h"


void setTitle(char *title) {
	char *str = malloc(sizeof(char) * 100);
	sprintf(str, "title %s", title);
	system(str);
	free(str);
}


void initConsole() {
	system("mode con cols=80 lines=40");
	setTitle("메 모 장");
	OnOff(0);
}


int loadFileList() {
	FILE* fp = fopen("fileList.txt", "rb");
	if (fp == NULL) {
		printf("현재 작성된 파일이 없습니다");
		return NULL;
	}



}
//해당 위치로 커서를 이동한다. 
void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서를 나타나게 하거나 끄는 함수 
void OnOff(int bool) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = bool;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

//비밀번호 설정 
void setPasswd() {
	char *pw = malloc(100);



}


//콘솔창 크기 설정

void setConsoleSize() {

	FILE* fpo;
	FILE* fpi;

	char command[COMMAND_SIZE] = { '\0', };
	int lines, cols;

	printf("세로의 크기를 입력해주세요.: ");
	scanf("%d", &lines);
	printf("가로의 크기를 입력해주세요.: ");
	scanf("%d", &cols);

	sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
	system(command); //콘솔창 해상도를 세팅 


	// 데이터를 백업 

	//데이터 작성하는 부분 
	fpo = fopen(SETTING_FILE, "wt");
	if (fpo == NULL) {
		fprintf(stderr, "파일 열기 오류\n");
		exit(1);
	}
	fprintf(fpo, "%d %d", lines, cols);
	fclose(fpo);

	//데이터 불러오는 부분 
	fpi = fopen(SETTING_FILE, "rt");
	if (fpi == NULL) {
		fprintf(stderr, "파일 열기 오류\n");
		exit(1);
	}
	fscanf(fpi, "%d %d", &lines, &cols);
	printf("\n세로: %d\n가로: %d\n", lines, cols);
	fclose(fpi);

}
// 텍스트의 색을 설정해줌
void setTextColor() {

}