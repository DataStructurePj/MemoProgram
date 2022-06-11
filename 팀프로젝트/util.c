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


//�ܼ�â ũ�� ����

void setConsoleSize() {

	FILE* fpo;
	FILE* fpi;

	char command[COMMAND_SIZE] = { '\0', };
	int lines, cols;

	printf("������ ũ�⸦ �Է����ּ���.: ");
	scanf("%d", &lines);
	printf("������ ũ�⸦ �Է����ּ���.: ");
	scanf("%d", &cols);

	sprintf(command, "mode con: lines=%d cols=%d", lines, cols);
	system(command); //�ܼ�â �ػ󵵸� ���� 


	// �����͸� ��� 

	//������ �ۼ��ϴ� �κ� 
	fpo = fopen(SETTING_FILE, "wt");
	if (fpo == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	fprintf(fpo, "%d %d", lines, cols);
	fclose(fpo);

	//������ �ҷ����� �κ� 
	fpi = fopen(SETTING_FILE, "rt");
	if (fpi == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	fscanf(fpi, "%d %d", &lines, &cols);
	printf("\n����: %d\n����: %d\n", lines, cols);
	fclose(fpi);

}

// �ؽ�Ʈ�� ���� ��������
void setTextColor() {
	FILE* fpo;
	FILE* fpi;

	int COLOR = 0;
	Colorselect();
	printf("���Ͻô� ���� ��ȣ�� �������ּ���.: ");
	scanf("%d", &COLOR);

	setrgb(COLOR);

	fpo = fopen(SETTING_FILE, "wt");
	if (fpo == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	fprintf(fpo, "%d", COLOR);
	fclose(fpo);

	fpi = fopen(SETTING_FILE, "rt");
	if (fpi == NULL) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	fscanf(fpi, "%d", &COLOR);
	printf("\n%d���� ���̽��ϴ�.\n", COLOR);
	fclose(fpi);
}

int Colorselect(void) {
	printf("\n"
		"\t1 = �Ķ���(Blue)                    2 = �ʷϻ�(Green)\n"
		"\t3 = ������(Red)                     4 = �����(Yellow)\n"
		"\t5 = �Ͼ��(White)"
		"\n"
	);
}

void setrgb(int color) {
	WORD attr = 6;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // GetConsoleScreenBufferInfo�� �ʿ�
	CONSOLE_SCREEN_BUFFER_INFO csbi;                    // GetConsoleScreenBufferInfo�� �ʿ�

	GetConsoleScreenBufferInfo(hConsole, &csbi);

	/* Foreground Color */
	switch (color) {
	case 1: // Blue !
		attr = FOREGROUND_BLUE;
		break;
	case 2: // Green ! 
		attr = FOREGROUND_GREEN;
		break;
	case 3: // Red ! 
		attr = FOREGROUND_RED;
		break;
	case 4: // Yellow ! 
		attr = FOREGROUND_RED | FOREGROUND_GREEN;
		break;
	case 5: // White (Gray: System Default) ! 
		attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		break;
	default:
		printf("�߸��� ��ȣ�Դϴ�.");
		Colorselect();
		break;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
}

void loadTextColor()
{
	int COLOR = 6;

	FILE* fp = fopen(SETTING_FILE, "rt");
	if (fp != NULL)
	{
		fscanf(fp, "%d", &COLOR);
		fclose(fp);
		setrgb(COLOR);
	}
}