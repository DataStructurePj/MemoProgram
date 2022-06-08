#include "main.h"

//파일을 작성한다. 
void writeFile(char Data[][MAX_ARRAY_SIZE], char filename[]) {
	FILE* stream; //파일 포인터를 선언한다.
	stream = fopen(filename, "w");
	if (stream == NULL) {
		fprintf(stderr, "\n'파일을 열 수 없습니다.'\n");
		exit(1);
	}
	for (int i = 0; Data[i][0] != '\0'; i++)
	{
		fwrite(Data[i], sizeof(char), MAX_ARRAY_SIZE, stream);
	}
	fclose(stream);
}

//메모 파일을 불러온다 
void readFile(char filename[], char contents[][MAX_ARRAY_SIZE]) {
	int size=0;
	FILE* file; //파일 포인터를 선언한다.
	file = fopen(filename, "r");
	int idx = 0;
	if (file == NULL) {
		fprintf(stderr, "\n파일을 열 수 없습니다.\n");
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




//데이터를 저장한다. 
char *writeData(int i) {
	char *filename = malloc(sizeof(char)*100); //파일명 
	char text[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] = { 0, };
	writeStc(text); //문장 입력 받음 
	sprintf(filename, "%sfile %d.txt", DATA_DIR, i);
	writeFile(text, filename);
	return filename;
}



//문장을 작성하는 함수 
void writeStc(char Data[][MAX_ARRAY_SIZE]) {
	int line = 0;
	printf("메모를 입력해주세요.\n");

	//이곳에 작성을 마치는 명령어를 제공한다. 
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
		fprintf(stderr, "\n'파일을 열 수 없습니다.'\n");
		return;
	}

	//모든 노드를 파일에 기록한다. 
	while (temp != NULL) {
		fwrite(temp, sizeof(Node), 1, file);
		temp = temp->link;
	}
	if (fwrite)
		printf("연결리스트가 정상적으로 파일에 저장되었습니다\n");
	else
		printf("연결리스트를 파일에 저장하는 중에 에러가 발생하였습니다\n");
	fclose(file);
}

void readLinkedList() {
	Node* temp = NULL;
	int idx = 0; int resultC = 0;
	FILE* file;
	file = fopen(LINKEDLIST_FILE_NAME, "rb");
	if (file == NULL) {
		writeLinkedList(getHead());
		fprintf(stderr, "\n파일을 열 수 없습니다.\n");
		exit(1);
	}

	//파일에서 연결리스트를 불러온다 
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
	
	//데이터를 불러온다
	readLinkedList();

	//사이즈를 체크하여 해당 사이즈를 int에 넣는다. 
	int Sz = size();


	//새파일 생성 
	char data[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE]={ 0 };
	memset(data, 0, sizeof(data));
	makeMemoDir();
	char *filePath = writeData(Sz);
	insert(Sz, filePath);


	print_list();



	
	//생성을 완료하면 노드에 추가 
	writeLinkedList(getHead());
	return 0;
}



//int showMenu(int lineSum, int line, char Data[][MAX_ARRAY_SIZE]) {
//	//화면 지우기 
//	system("cls");
//	int result = 0;
//	//메뉴 알림 
//	if (line != lineSum)printf("값이 다릅니다\n");
//	printf("p를 누르면 작성이 중단 됩니다.\n");
//	//현재 데이터 출력 
//	for (int i = 0; i <= line; i++) puts(Data[i]);
//	//메뉴 입력 
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