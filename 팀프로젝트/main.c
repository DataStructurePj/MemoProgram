#include "main.h"
int main() {

	loadTheme();
	while (1) {
		initConsole();
		
		
		//initialize

		system("cls");
		titleDraw();
		int menuCode = menuDraw();
		char data[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };
		int Sz = 0;
		//data load 
		init_list();
		system("cls");
		readLinkedList();
		system("cls");
		Sz = size();

		//main loop
		switch (menuCode)
		{
		case 0: //새 메모 작성
			editNewFile(Sz);
			break;
		case 1: //메모 불러오기
			loadFiles(data);
			break;
		case 2: //도움말
			break;
		case 3: //옵션
			setTheme();
			break;
		case 4: //종료 
			finish();
		}
	}
	return 0;
}

//각 메뉴들 정의 

void editNewFile(int size) {
	setTitle("새 메모");
	OnOff(1);
	writeData(size);
	writeLinkedList(getHead());
	system("cls");
	OnOff(0);
}

void loadFiles(char data[][MAX_ARRAY_SIZE]) {
	setTitle("메모 열기");
	memset(data, 0, sizeof(data));
	OnOff(1);
	//파일목록 제공 
	print_list();
	printf("출력: %s\n", get_entry(0)->data);
	//제공한 파일 편집하는 함수 
	/*writeStc(); */
	OnOff(0);
	Sleep(3000);
	system("cls");
}

void finish() {
	OnOff(1);
	if (showAlert("프로그램을 종료하시겠습니까?")) {
		system("cls");
		printf("메모장 프로그램을 종료합니다 \n");
		exit(1);
	}
	OnOff(0);
}
