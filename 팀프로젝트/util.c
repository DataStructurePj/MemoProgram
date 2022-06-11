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
//�ش� ��ġ�� Ŀ���� �̵��Ѵ�. 
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

//��й�ȣ ���� 
void setPasswd() {
	char *pw = malloc(100);



}

void setTheme() {
	FILE* fpo;
	FILE* fpi;
	int tmp[2] = { 0, };


	printf("���� ����\n"
		"\t1 = ������(Black)                   2 = �Ͼ��(White)\n"
		"\t3 = �ʷϻ�(Green)                   4 = ������(Red)\n"
		"\t5 = �����(Yellow)                  6 = �Ķ���(Blue)\n"
		"\n"
	);
	printf("��� ����\n"
		"\t1. ������(Black)                    2. �Ͼ��(White)\n");
	printf("\n���Ͻô� ���� ��ȣ�� ������� �Է����ּ���.(���� ��ȣ, ��� ��ȣ): ");
	scanf("%d %d", &tmp[0], &tmp[1]);

	selectTheme(tmp);
	fpo = fopen(Background_FILE, "wt");
	if (fpo == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	fwrite(COLOR, sizeof(COLOR), 1, fpo);
	fclose(fpo);

	fpi = fopen(Background_FILE, "rt");
	if (fpi == NULL) {
		fprintf(stderr, "���� ���� ����\n");
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // GetConsoleScreenBufferInfo�� �ʿ�
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
		printf("�߸��� ��ȣ�Դϴ�.");
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