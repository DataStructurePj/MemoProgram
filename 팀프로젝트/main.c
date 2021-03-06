#include "main.h"
int main() {

	loadTheme();
	while (1) {
		initConsole();
		
		
		//initialize

		system("cls");
		titleDraw();
		int menuCode = menuDraw();
		int Sz = 0;
		//data load 
		init_list();
		system("cls");
		readLinkedList();
		system("cls");
		Sz = size();
		
		//main loop
		setTitle(menuList[menuCode]);
		switch (menuCode)
		{
		
		case 0: //새 메모 작성
			editNewFile(Sz);
			break;
		case 1: //메모 불러오기
			loadFiles(Sz);
			break;
		case 2: //도움말
			system("cls");
			showHelp();
			while (_getch() != 27) {
			}
			break;
		case 3: //옵션
			OnOff(1);
			setTheme();
			OnOff(0);
			break;
		case 4: //종료 
			finish();
		}
	}
	return 0;
}

//각 메뉴들 정의 

void editNewFile(int size) {
	system("mode con cols=100 lines=40");
	OnOff(1);
	writeData(size,NULL,NULL);
	
	system("cls");
	OnOff(0);
}

void loadFiles(int sz) {
	char select = 0;
	char data[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };
	char *filename = malloc(100);
	memset(data, 0, sizeof(data));
	OnOff(1);
	//파일목록 제공 
	print_list();
	printf("\n열 파일을 선택해 주세요(메인메뉴이동 : ESC) :  ");
	select = _getch();
	//범위 초과 혹은 메인 메뉴 이동 
	if (select == 27 || (select > size()+'0' || select <'1')) {
		char str[2][100] = { 0, };
		strcpy(str[0], "메인메뉴로 돌아갑니다.");
		strcpy(str[1], "허용되지 않는 범위 입니다. 메인메뉴로 돌아갑니다.");
		system("cls");
		printf("%s", select == 27? str[0]:str[1]);
		Sleep(3000);
		return;
	}

	//select변수 갱신
	select = select - '0' ;
	printf("%d", select);
	
	strcpy(filename, get_entry(select - 1)->data);

	printf("출력: %s\n", filename);
	setTitle(filename);
	readFile(filename, data);
	writeData(sz, data, filename);
	OnOff(0);
	free(filename);
}

void finish() {
	OnOff(1);
	if (showAlert("프로그램을 종료하시겠습니까?",NULL)==1) {
		system("cls");
		printf("메모장 프로그램을 종료합니다 \n");
		exit(1);
	}
	OnOff(0);
}
