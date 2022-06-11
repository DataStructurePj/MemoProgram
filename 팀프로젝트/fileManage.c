#include "main.h"
#define CURSORX 0
#define CURSORY 4

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

int returnCode(int code) {


}




void printNow(char data[][MAX_ARRAY_SIZE]) {
	int i = 0;
	int width = 0;
	for (i = 0; data[i][0]!='\0'; i++) {
		gotoxy(CURSORX, CURSORY + i);
		printf("%s\n", data[i]);
		width = i>0?strlen(data[i])-1: strlen(data[i]);
	}
	gotoxy(CURSORX+width, CURSORY + i-1);
}


//�����͸� �����Ѵ�. 
void writeData(int idx) {
	char *filename = malloc(sizeof(char) * 100); //���ϸ� 
	char text[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
	memset(text, '\0', sizeof(text));
	int line = 0;
	char mode;
	char cmp; int index = 0;
	makeMemoDir();

	//��带 ������ �� �ִ� �κ� 
	while (1) {
		system("cls");
		printf("------------------------------------------------------\n");
		printf("��带 �Է��� �ּ��� (i:���� ,p: ����, r: ���� �����)\n");
		printf("------------------------------------------------------\n\n");
		printNow(text);
		mode = _getch();
		system("cls");
	
		switch (mode) {
		case 'i':
			
			while (1) {
				system("cls");
				printf("--------------------\n");
				printf("�޸� �Է����ּ���.\n");
				printf("--------------------\n\n");
				printNow(text);
				cmp = _getch();
				if (cmp == 27) break; //esc������ �ݺ��� Ż�� 
				if (cmp == '\r' || index == MAX_ARRAY_SIZE-1) {
					text[line][index] = '\0';
					index = 0;
					line++;
				}
				if (cmp == '\b'&&index > 0) {
					text[line][index--] = '\0';
					
				}
				else {
					text[line][index] = cmp;
					index++;
				}
			}
			break;
		case 'p': 
			gotoxy(CURSORX, CURSORY-2);
			printf("_______________________������ ����_____________________\n");
			printNow(text);
			printf("\n_______________________________________________________\n\n");
			fflush(stdin);
			if (showAlert("�����Ͻðڽ��ϱ�?")) {
				defineFileName(filename, text, line, idx);
				return;
			}
			break;
		case 'r': //���ο� ������ ���� 
			memset(text, '\0', sizeof(text));
			line = 0;
			mode = 0;
			cmp = 0; index = 0;
			break;
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


