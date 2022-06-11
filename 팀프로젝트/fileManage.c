#include "main.h"

//������ �ۼ��Ѵ�. 
void writeFile(char Data[][MAX_ARRAY_SIZE], char filename[]) {
	FILE* stream; //���� �����͸� �����Ѵ�.
	char *tmp=malloc(sizeof(char)*100);
	sprintf(tmp, "%s%s.txt", DATA_DIR, filename);
	stream = fopen(tmp, "w");
	if (stream == NULL) {
		fprintf(stderr, "\n'������ �� �� �����ϴ�.'\n");
		exit(1);
	}
	for (int i = 0; Data[i][0] != '\0'; i++)
	{
		int length=strlen(Data[i]);
		Data[i][length] = '\n';
		fwrite(Data[i], sizeof(char),length+1, stream);
	}
	free(tmp);
	fclose(stream);
}

//�޸� ������ �ҷ��´� 
void readFile(char filename[], char contents[][MAX_ARRAY_SIZE]) {
	int size=0;
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




//�����͸� �����Ѵ�. 
void writeData(int idx) {
	char *filename = malloc(sizeof(char)*100); //���ϸ� 
	char text[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0, };
	memset(text, 0, sizeof(text));
	int line = 0;

	makeMemoDir();
	printf("�޸� �Է����ּ���.\n");
	//�̰��� �ۼ��� ��ġ�� ��ɾ �����Ѵ�. 
	while (line < 4) {
		gets(text[line]);
		line++;
	}
	//������ ���� ���� �ۼ��ϴ� ���� 
	
	printf("--------------------------------------");
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



	//sprintf(filename, "%sfile %d.txt", DATA_DIR, idx);
	writeFile(text, filename);
	insert(idx, filename);
	free(filename);
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
		if (resultC==0) break;
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






