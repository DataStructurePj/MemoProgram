#include "main.h"

int main() {
	init();
	init_list();




	while (1) {
		//initialize
		int menuCode = menuDraw();
		
		//data load 
		head = readLinkedList(); //������ ����� ���Ḯ��Ʈ�� �ҷ��´�. 



		//main loop
		switch (menuCode)
		{
			//�� ���� ���� �޴� ����
		case 0:
			break;

			//������ �ۼ��� ���� ��� �����ְ�, ������ ���� �����ϴ� ��� ���� 
		case 1:
			system("cls");
			OnOff(1);
			//���ϸ�� ���� 

			//������ ���� �����ϴ� �Լ� 
			writeStc(); 
			OnOff(0);
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
