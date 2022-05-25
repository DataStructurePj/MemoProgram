#include "main.h"

int main() {
	init();
	while (1) {
		int menuCode = menuDraw();

		switch (menuCode)
		{
			//새 파일 생성 메뉴 선택
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;


		default:
			break;
		}

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
