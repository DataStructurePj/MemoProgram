#include "main.h"

int main() {
	init();
	while (1) {
		int menuCode = menuDraw();

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
