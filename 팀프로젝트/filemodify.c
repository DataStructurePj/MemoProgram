#include "main.h"



int loadFileList() {
	FILE* fp = fopen("fileList.txt", "rb");
	if (fp == NULL) {
		printf("현재 작성된 파일이 없습니다");
		return NULL;
	}



}

void writeFile(char Data[][MAX_ARRAY_SIZE]) {

}

int returnCode(int code) {


}

int showMenu(int lineSum,int line, char Data[][MAX_ARRAY_SIZE]) {
	//화면 지우기 
	system("cls");
	int result = 0;
	//메뉴 알림 
	if (line != lineSum)printf("값이 다릅니다\n");
	printf("p를 누르면 작성이 중단 됩니다.\n");
	//현재 데이터 출력 
	for (int i = 0; i <= line; i++) puts(Data[i]);
	//메뉴 입력 
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

