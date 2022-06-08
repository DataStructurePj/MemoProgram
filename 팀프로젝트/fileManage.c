#include "main.h"

//������ �ۼ��Ѵ�. 
void writeFile(char Data[][MAX_ARRAY_SIZE], char filename[]) {
	FILE* stream; //���� �����͸� �����Ѵ�.
	stream = fopen(filename, "w");
	if (stream == NULL) {
		fprintf(stderr, "\n'������ �� �� �����ϴ�.'\n");
		exit(1);
	}
	for (int i = 0; Data[i][0] != '\0'; i++)
	{
		fwrite(Data[i], sizeof(char), MAX_ARRAY_SIZE, stream);
	}
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
char *writeData(int i) {
	char *filename = malloc(sizeof(char)*100); //���ϸ� 
	char text[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0, };
	writeStc(text); //���� �Է� ���� 
	sprintf(filename, "%sfile %d.txt", DATA_DIR, i);
	writeFile(text, filename);
	return filename;
}



//������ �ۼ��ϴ� �Լ� 
void writeStc(char Data[][MAX_ARRAY_SIZE]) {
	int line = 0;
	printf("�޸� �Է����ּ���.\n");

	//�̰��� �ۼ��� ��ġ�� ��ɾ �����Ѵ�. 
	while (line < 4) {

		gets(Data[line]);
		line++;
	}
}

void writeLinkedList(Node *head) {
	Node* temp = head;
	FILE* file;
	file = fopen(LINKEDLIST_FILE_NAME, "wb");
	if (file == NULL) {
		fprintf(stderr, "\n'������ �� �� �����ϴ�.'\n");
		return;
	}

	//��� ��带 ���Ͽ� ����Ѵ�. 
	while (temp != NULL) {
		fwrite(temp, sizeof(Node), 1, file);
		temp = temp->link;
	}
	if (fwrite)
		printf("���Ḯ��Ʈ�� ���������� ���Ͽ� ����Ǿ����ϴ�\n");
	else
		printf("���Ḯ��Ʈ�� ���Ͽ� �����ϴ� �߿� ������ �߻��Ͽ����ϴ�\n");
	fclose(file);
}

void readLinkedList() {
	Node* temp = NULL;
	int idx = 0; int resultC = 0;
	FILE* file;
	file = fopen(LINKEDLIST_FILE_NAME, "rb");
	if (file == NULL) {
		writeLinkedList(getHead());
		fprintf(stderr, "\n������ �� �� �����ϴ�.\n");
		exit(1);
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

int main()
{
	init_list();
	
	//�����͸� �ҷ��´�
	readLinkedList();

	//����� üũ�Ͽ� �ش� ����� int�� �ִ´�. 
	int Sz = size();


	//������ ���� 
	char data[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE]={ 0 };
	memset(data, 0, sizeof(data));
	makeMemoDir();
	char *filePath = writeData(Sz);
	insert(Sz, filePath);


	print_list();



	
	//������ �Ϸ��ϸ� ��忡 �߰� 
	writeLinkedList(getHead());
	return 0;
}



//int showMenu(int lineSum, int line, char Data[][MAX_ARRAY_SIZE]) {
//	//ȭ�� ����� 
//	system("cls");
//	int result = 0;
//	//�޴� �˸� 
//	if (line != lineSum)printf("���� �ٸ��ϴ�\n");
//	printf("p�� ������ �ۼ��� �ߴ� �˴ϴ�.\n");
//	//���� ������ ��� 
//	for (int i = 0; i <= line; i++) puts(Data[i]);
//	//�޴� �Է� 
//	int p = _getch();
//	if (p == 'p') {
//		save(line, Data);
//		result = 200;
//	}
//	return result;
//}










//void displayLinkedList(Node *root)
//{
//	Node *temp = root;
//	printf("\nLinkedList \n");
//	while (temp != NULL)
//	{
//		printf("filename:  %s: \n", temp->data.filename);
//		printf("contents");
//		for (int i = 0; temp->data.data[i]!=""; i++) {
//			printf("%s \n", temp->data.data[i]);
//		}
//		printf("--------------------------\n");
//		temp = temp->link;
//	}
//	printf("NULL\n\n");
//}
//
//Node *insertAtBegin(Node *head, char data[][MAX_ARRAY_SIZE], char filename[]) {
//
//	Node *ptr;
//	Node *temp = (Node*)malloc(sizeof(Node));
//	strcpy(temp->data.data, data);
//	strcpy(temp->data.filename, filename);
//	temp->link = NULL;
//	if (head == NULL) head = temp;
//	else {
//		temp->link = head;
//		head = temp;
//	}
//	return head;
//}