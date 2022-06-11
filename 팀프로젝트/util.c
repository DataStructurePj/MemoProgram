#include "main.h"

int COLOR[2] = { 0, };

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

void setTheme() {
	FILE* fpo;
	FILE* fpi;
	int tmp[2] = { 0, };


	printf("글자 색깔\n"
		"\t1 = 검정색(Black)                   2 = 하얀색(White)\n"
		"\t3 = 초록색(Green)                   4 = 빨간색(Red)\n"
		"\t5 = 노란색(Yellow)                  6 = 파란색(Blue)\n"
		"\n"
	);
	printf("배경 색깔\n"
		"\t1. 검은색(Black)                    2. 하얀색(White)\n");
	printf("\n원하시는 색깔 번호를 순서대로 입력해주세요.(글자 번호, 배경 번호): ");
	scanf("%d %d", &tmp[0], &tmp[1]);

	selectTheme(tmp);
	fpo = fopen(Background_FILE, "wt");
	if (fpo == NULL) {
		fprintf(stderr, "파일 열기 오류\n");
		exit(1);
	}
	fwrite(COLOR, sizeof(COLOR), 1, fpo);
	fclose(fpo);

	fpi = fopen(Background_FILE, "rt");
	if (fpi == NULL) {
		fprintf(stderr, "파일 열기 오류\n");
		exit(1);
	}
	fread(COLOR, sizeof(COLOR), 1, fpi);
	fclose(fpi);
}

void loadTheme()
{

	FILE* fp = fopen(Background_FILE, "rt");
	if (fp != NULL)
	{
		fread(COLOR, sizeof(COLOR), 1, fp);
		fclose(fp);
		selectTheme(COLOR);
	}
}

void selectTheme(int rgb[]) {
	WORD attr = 2;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // GetConsoleScreenBufferInfo에 필요
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	int fc = rgb[0];
	int bc = rgb[1];

	if (fc == bc)
		return;
	switch (fc) {
	case 1: // Black!
		COLOR[0] = fc;
		attr = 0;
		break;
	case 2: // White !
		COLOR[0] = fc;
		attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		break;
	case 3: // Green ! 
		COLOR[0] = fc;
		attr = FOREGROUND_GREEN;
		break;
	case 4: // Red ! 
		COLOR[0] = fc;
		attr = FOREGROUND_RED;
		break;
	case 5: // Yellow ! 
		COLOR[0] = fc;
		attr = FOREGROUND_RED | FOREGROUND_GREEN;
		break;
	case 6: // Blue (Gray: System Default) ! 
		COLOR[0] = fc;
		attr = FOREGROUND_BLUE;
		break;
	default:
		printf("잘못된 번호입니다.");
		break;
	}

	switch (bc)
	{
	case 1: // Black
		attr = attr | 0;
		break;
	case 2: // White
		attr = attr | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
	default:
		attr = (fc == 2 || fc == 3 || fc == 5) ? attr | 0 : attr | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		COLOR[1] = (fc == 2 || fc == 3 || fc == 5) ? 1 : 2;
		break;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
}