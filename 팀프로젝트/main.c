#include "main.h"
int main() {


	while (1) {
		initConsole();
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
		case 0: //�� �޸� �ۼ�
			editNewFile(Sz);
			break;
		case 1: //�޸� �ҷ�����
			loadFiles(data);
			break;
		case 2: //����
			break;
		case 3: //�ɼ�
			showOptionMenu();
			break;
		case 4: //���� 
			finish();
		}
	}
	return 0;
}

//�� �޴��� ���� 

void editNewFile(int size) {
	setTitle("�� �޸�");
	OnOff(1);
	writeData(size);
	writeLinkedList(getHead());
	system("cls");
	OnOff(0);
}

void loadFiles(char data[][MAX_ARRAY_SIZE]) {
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
}

void finish() {
	OnOff(1);
	if (showAlert("���α׷��� �����Ͻðڽ��ϱ�?")) {
		system("cls");
		printf("�޸��� ���α׷��� �����մϴ� \n");
		exit(1);
	}
	OnOff(0);
}
void showOptionMenu() {
	int select = 0;
	printf("1. �ػ� ���� \n2. ��Ʈ ���� ���� \n");
	scanf("%d", &select);
	switch (select) {
	case 1: // 1���� �������� ���
		//setConsoleSize();
		break;
	case 2: //2���� �������� ��� 
		//setTextColor();
		break;
	}


}