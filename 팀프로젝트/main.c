#include "main.h"

int main() {
	init();

	while (1) {
		
		titleDraw();
		
		//initialize
		int menuCode = menuDraw();
		char data[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0 };
		int Sz = 0;

		//data load 
		init_list();
		readLinkedList();
		system("cls");
		Sz = size();



		//main loop
		switch (menuCode)
		{
			//새 파일 생성 메뉴 선택
		case 0:
			OnOff(1);
			writeData(Sz);
			writeLinkedList(getHead());
			system("cls");
			OnOff(0);
			break;
			//기존에 작성한 파일 목록 보여주고, 선택한 파일 수정하는 기능 제공 
		case 1:
			memset(data, 0, sizeof(data));
			system("cls");
			OnOff(1);
			//파일목록 제공 
			print_list();
			//제공한 파일 편집하는 함수 
			/*writeStc(); */
			OnOff(0);
			Sleep(3000);
			system("cls");
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}
	return 0;
}
