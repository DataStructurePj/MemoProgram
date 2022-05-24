#include "main.h"

int main() {
	init();
	while (1) {
		int menuCode = menuDraw();
		//새 파일 생성 메뉴 선택 
		if (menuCode == 0) {


			system("cls");
			printf("1번 선택\n");
			Sleep(2000);
			system("cls");
			init();
		}
		else if (menuCode == 1) {
			system("cls");
			printf("2번 선택\n");
			Sleep(2000);
			system("cls");
			init();
		}
	}
	return 0;
}
 