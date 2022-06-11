#include "main.h"

//������ �ۼ��Ѵ�. 
void writeFile(char Data[][MAX_ARRAY_SIZE], char filename[]) {
	FILE* stream; //���� �����͸� �����Ѵ�.
	char *tmp = malloc(sizeof(char) * 100);
	sprintf(tmp, "%s%s.txt", DATA_DIR, filename);
	stream = fopen(tmp, "w");
	if (stream == NULL) {
		fprintf(stderr, "\n'������ �� �� �����ϴ�.'\n");
		exit(1);
	}
	for (int i = 0; Data[i][0] != '\0'; i++)
	{
		int length = strlen(Data[i]);
		fwrite(Data[i], sizeof(char), length + 1, stream);
	}
	free(tmp);
	fclose(stream);
}

//�޸� ������ �ҷ��´� 
void readFile(char filename[], char contents[][MAX_ARRAY_SIZE]) {
	int size = 0;
	FILE* file; //���� �����͸� �����Ѵ�.
	file = fopen(filename, "r");
	int idx = 0;
	if (file == NULL) {
		fprintf(stderr, "\n������ �� �� �����ϴ�.\n");
		exit(1);
	}
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	fread(contents, sizeof(char), size, file);
	fclose(file);
}

//���� ���Ḯ��Ʈ�� ����Ǿ��ִ� ������ ����� ����Ѵ�. 
void printNow(char data[][MAX_ARRAY_SIZE]) {
	int i = 0;
	int width = 0;
	for (i = 0; data[i][0]!='\0' ; i++) {
		gotoxy(CURSORX, CURSORY + i);
		printf("%s\n", data[i]);
		width = i>0?strlen(data[i])-1: strlen(data[i]);
	}
	gotoxy(CURSORX+width, i>0? CURSORY + i - 1: CURSORY + i);
}


//�����͸� �����Ѵ�. 
void writeData(int idx, char data[][MAX_ARRAY_SIZE]) {
	char *filename = malloc(sizeof(char) * 100); //���ϸ� 
	char text[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
	memset(text, '\0', sizeof(text));
	if (data != NULL) for (int i = 0; data[i][0] != '\0'; i++) {
		strcpy(text[i], data[i]);
	}
	int line = 0;
	char mode;
	char cmp; int index = 0;
	makeMemoDir();

	//��带 ������ �� �ִ� �κ� 
	while (1) {
		system("cls");
		OnOff(0);
		printf("----------------------------------------------------------------\n");
		printf("��带 �Է��� �ּ���\n");
		printf("(i:���� ,p: ����, r: ���� �����, escŰ : ����ȭ�� �̵�)\n");
		printf("----------------------------------------------------------------\n\n");
		printNow(text);
		mode = _getch();
		system("cls");
		OnOff(1);
		int b = 0;
		switch (mode) {
		case 'i':
			while (1) {
				system("cls");
				printf("-----------------------------------\n");
				printf("�޸� �Է����ּ���.\n");
				printf("(ESC�� ������ ��� ���� ȭ���̵�)\n");
				printf("-----------------------------------\n\n");
				printNow(text);
				cmp = _getch();
				
				//ESCŰ�� �Է¹��� ���
				if (cmp == 27) break; //�ݺ��� Ż�� 

				//����Ű�� �Է¹��� ���
				if (cmp == '\r' || index == MAX_ARRAY_SIZE-1&&b==0) {
					text[line][index] = '\n';
					index = 0;
					b = 0;
					line++;
				}

				//BackSpace�� �Է¹��� ���
				if (cmp == '\b') {
					if (index > 0) {
						index--;
						text[line][index] = '\0';
					}
					else if (index == 0 && line > 0) {
						text[line][index] = '\0';
						index = MAX_ARRAY_SIZE - 1;
						b = 1;
						line--;
					}
				}
				//����Ű�� ������ �ʵ��� ���� 
				else if(cmp!=-32) {
					text[line][index] = cmp;
					index++;
				}
			}
			break;
		case 'p': 
			if (index != 0) {
				gotoxy(CURSORX, CURSORY - 2);
				printf("_______________________������ ����_____________________\n");
				printNow(text);
				printf("\n_______________________________________________________\n\n");
				int ret = showAlert("�����Ͻðڽ��ϱ�?",1);

				if (ret==1) {
					defineFileName(filename, text, line, idx);
					writeLinkedList(getHead());
					return;
				}
				else if (ret == 2) return;
			}
			else {
				printf("������ �����Ͱ� �����ϴ�.");
				Sleep(500);
			}
			
			break;
		case 'r': //���ο� ������ ���� 
			memset(text, '\0', sizeof(text));
			line = 0;
			mode = 0;
			cmp = 0; index = 0;
			break;
		case ESC:
			return;
		}
	}
}

void writeLinkedList(Node *head) {
	Node* temp = head;
	FILE* file;
	file = fopen(LINKEDLIST_FILE_NAME, "wb");
	if (file == NULL) {
		exit(1);
	}

	//��� ��带 ���Ͽ� ����Ѵ�. 
	while (temp != NULL) {
		fwrite(temp, sizeof(Node), 1, file);
		temp = temp->link;
	}
	if (fwrite)
		printf("������ ���������� ���Ḯ��Ʈ�� ����Ǿ����ϴ�\n");
	else
		printf("���Ḯ��Ʈ�� ���Ͽ� �����ϴ� �߿� ������ �߻��Ͽ����ϴ�\n");
	Sleep(3000);
	fclose(file);
}

void readLinkedList() {
	Node* temp = NULL;
	int idx = 0; int resultC = 0;
	FILE* file;
	file = fopen(LINKEDLIST_FILE_NAME, "rb");
	if (file == NULL) {
		fprintf(stderr, "\n�� ����� �����մϴ�.\n");
		writeLinkedList(getHead());
		return;
	}

	//���Ͽ��� ���Ḯ��Ʈ�� �ҷ��´� 
	while (1) {
		temp = (Node *)malloc(sizeof(Node));
		resultC = fread(temp, sizeof(Node), 1, file);
		if (resultC == 0) break;
		insert(idx, temp->data);
		free(temp);
		idx++;
	}
	fclose(file);
}
void makeMemoDir() {
	char *strFolderPath = malloc(100);
	sprintf(strFolderPath, "./%s", DATA_DIR);
	mkdir(strFolderPath);
	free(strFolderPath);
}



void defineFileName(char *filename, char text[][MAX_ARRAY_SIZE], int line,int idx) {
	printf("\n--------------------------------------");
	while (1) {
		printf("\n������ ���� ���� �Է��� �ּ���: ");
		scanf("%s", filename);
		if (!findFileName(filename)) break;
		else {
			system("cls");
			printf("�ߺ��Ǵ� ������ �ֽ��ϴ�. �ٸ� ���ϸ��� �Է����ּ���. \n\n");
			printf("------[������ ����]-------\n\n");
			for (int i = 0; i < line; i++) {
				printf("%s\n", text[i]);
			}
			printf("\n--------------------------\n");
		}
	}
	writeFile(text, filename);
	insert(idx, filename);
	free(filename);
}


