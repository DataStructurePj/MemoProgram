#include "main.h"
int main() {

	loadTheme();
	while (1) {
		initConsole();
		
		
		//initialize

		system("cls");
		titleDraw();
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
		setTitle(menuList[menuCode]);
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
			OnOff(1);
			setTheme();
			OnOff(0);
			break;
		case 4: //���� 
			finish();
		}
	}
	return 0;
}

//�� �޴��� ���� 

void editNewFile(int size) {
	system("mode con cols=100 lines=40");
	OnOff(1);
	writeData(size,NULL);
	
	system("cls");
	OnOff(0);
}

void loadFiles(char data[][MAX_ARRAY_SIZE]) {
	char select = 0;
	memset(data, 0, sizeof(data));
	OnOff(1);
	//���ϸ�� ���� 
	print_list();
	printf("\n�� ������ ������ �ּ���(���θ޴��̵� : ESC) :  ");
	select = _getch();
	//���� �ʰ� Ȥ�� ���� �޴� �̵� 
	if (select == 27 || (select > size()+'1' || select <'1')) {
		char str[2][100] = { 0, };
		strcpy(str[0], "���θ޴��� ���ư��ϴ�.");
		strcpy(str[1], "������ �ʴ� ���� �Դϴ�. ���θ޴��� ���ư��ϴ�.");
		system("cls");
		printf("%s", select == 27? str[0]:str[1]);
		Sleep(3000);
		return;
	}

	//select���� ����
	select = select - '0' ;
	printf("%d", select);


	printf("���: %s\n", get_entry(select-1)->data);
	//������ ���� �����ϴ� �Լ� 
	/*writeStc(); */
	OnOff(0);
	Sleep(3000);
	system("cls");
}

void finish() {
	OnOff(1);
	if (showAlert("���α׷��� �����Ͻðڽ��ϱ�?",NULL)==1) {
		system("cls");
		printf("�޸��� ���α׷��� �����մϴ� \n");
		exit(1);
	}
	OnOff(0);
}
