#include "main.h"

int main() {


	while (1) {
		init();
		titleDraw();
		
		//initialize

		system("cls");
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
			//�� ���� ���� �޴� ����
		case 0:
			setTitle("�� �޸�");
			OnOff(1);
			writeData(Sz);
			writeLinkedList(getHead());
			system("cls");
			OnOff(0);
			break;
			//������ �ۼ��� ���� ��� �����ְ�, ������ ���� �����ϴ� ��� ���� 
		case 1:
			setTitle("�޸� ����");
			memset(data, 0, sizeof(data));
			OnOff(1);
			//���ϸ�� ���� 
			print_list();
			printf("���: %s\n", get_entry(0)->data);
			//������ ���� �����ϴ� �Լ� 




			/*writeStc(); */
			OnOff(0);
			Sleep(3000);
			system("cls");
			break;
		case 2:
			break;
		case 3:
			OnOff(1);
			if (showAlert("���α׷��� �����Ͻðڽ��ϱ�?")) {
				system("cls");
				printf("�޸��� ���α׷��� �����մϴ� \n");
				exit(1);
			}
			OnOff(0);
			break;
		}
	}
	return 0;
}
