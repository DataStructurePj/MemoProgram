#include "main.h"



int loadFileList() {
	FILE* fp = fopen("fileList.txt", "rb");
	if (fp == NULL) {
		printf("���� �ۼ��� ������ �����ϴ�");
		return NULL;
	}



}

void writeFile(char Data[][MAX_ARRAY_SIZE]) {

}

int returnCode(int code) {


}

int showMenu(int lineSum,int line, char Data[][MAX_ARRAY_SIZE]) {
	//ȭ�� ����� 
	system("cls");
	int result = 0;
	//�޴� �˸� 
	if (line != lineSum)printf("���� �ٸ��ϴ�\n");
	printf("p�� ������ �ۼ��� �ߴ� �˴ϴ�.\n");
	//���� ������ ��� 
	for (int i = 0; i <= line; i++) puts(Data[i]);
	//�޴� �Է� 
	int p = _getch();
	if (p== 'p')result = 200;
	else if (p == 'k') return showMenu(lineSum,line-1,Data);
	return result;
}
void writeStc() {
	int line = 0;
	char Data[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0, };
	while (line < MAX_ARRAY_SIZE - 1) {
		if (showMenu(line,line,Data) == 200) {
			system("cls");
			break;
		}
		gets(Data[line]);
		line++;
	}
}

