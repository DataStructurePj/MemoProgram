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
			//�� ���� ���� �޴� ����
		case 0:
			OnOff(1);
			writeData(Sz);
			writeLinkedList(getHead());
			system("cls");
			OnOff(0);
			break;
			//������ �ۼ��� ���� ��� �����ְ�, ������ ���� �����ϴ� ��� ���� 
		case 1:
			memset(data, 0, sizeof(data));
			system("cls");
			OnOff(1);
			//���ϸ�� ���� 
			print_list();
			//������ ���� �����ϴ� �Լ� 
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
