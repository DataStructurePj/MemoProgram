#include "main.h"

int main() {
	init();
	while (1) {
		int menuCode = menuDraw();
		//�� ���� ���� �޴� ���� 
		if (menuCode == 0) {


			system("cls");
			printf("1�� ����\n");
			Sleep(2000);
			system("cls");
			init();
		}
		else if (menuCode == 1) {
			system("cls");
			printf("2�� ����\n");
			Sleep(2000);
			system("cls");
			init();
		}
	}
	return 0;
}
 