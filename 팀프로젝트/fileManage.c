#include "main.h"

//파일을 작성한다. 
void writeFile(char Data[][MAX_ARRAY_SIZE], char filename[]) {
	FILE* stream; //파일 포인터를 선언한다.
	char *tmp = malloc(sizeof(char) * 100);
	sprintf(tmp, "%s%s.txt", DATA_DIR, filename);
	stream = fopen(tmp, "w");
	if (stream == NULL) {
		fprintf(stderr, "\n'파일을 열 수 없습니다.'\n");
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

//메모 파일을 불러온다 
void readFile(char filename[], char contents[][MAX_ARRAY_SIZE]) {
	int size = 0;
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

//현재 연결리스트에 저장되어있는 데이터 목록을 출력한다. 
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


//데이터를 저장한다. 
void writeData(int idx, char data[][MAX_ARRAY_SIZE]) {
	char *filename = malloc(sizeof(char) * 100); //파일명 
	char text[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
	memset(text, '\0', sizeof(text));
	if (data != NULL) for (int i = 0; data[i][0] != '\0'; i++) {
		strcpy(text[i], data[i]);
	}
	int line = 0;
	char mode;
	char cmp; int index = 0;
	makeMemoDir();

	//모드를 변경할 수 있는 부분 
	while (1) {
		system("cls");
		OnOff(0);
		printf("----------------------------------------------------------------\n");
		printf("모드를 입력해 주세요\n");
		printf("(i:편집 ,p: 저장, r: 새로 만들기, esc키 : 메인화면 이동)\n");
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
				printf("메모를 입력해주세요.\n");
				printf("(ESC를 누르면 모드 선택 화면이동)\n");
				printf("-----------------------------------\n\n");
				printNow(text);
				cmp = _getch();
				
				//ESC키를 입력받은 경우
				if (cmp == 27) break; //반복문 탈출 

				//엔터키를 입력받은 경우
				if (cmp == '\r' || index == MAX_ARRAY_SIZE-1&&b==0) {
					text[line][index] = '\n';
					index = 0;
					b = 0;
					line++;
				}

				//BackSpace를 입력받은 경우
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
				//방향키를 누르지 않도록 방지 
				else if(cmp!=-32) {
					text[line][index] = cmp;
					index++;
				}
			}
			break;
		case 'p': 
			if (index != 0) {
				gotoxy(CURSORX, CURSORY - 2);
				printf("_______________________저장할 내용_____________________\n");
				printNow(text);
				printf("\n_______________________________________________________\n\n");
				int ret = showAlert("저장하시겠습니까?",1);

				if (ret==1) {
					defineFileName(filename, text, line, idx);
					writeLinkedList(getHead());
					return;
				}
				else if (ret == 2) return;
			}
			else {
				printf("저장할 데이터가 없습니다.");
				Sleep(500);
			}
			
			break;
		case 'r': //새로운 문서로 시작 
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

	//모든 노드를 파일에 기록한다. 
	while (temp != NULL) {
		fwrite(temp, sizeof(Node), 1, file);
		temp = temp->link;
	}
	if (fwrite)
		printf("파일이 정상적으로 연결리스트에 저장되었습니다\n");
	else
		printf("연결리스트를 파일에 저장하는 중에 에러가 발생하였습니다\n");
	Sleep(3000);
	fclose(file);
}

void readLinkedList() {
	Node* temp = NULL;
	int idx = 0; int resultC = 0;
	FILE* file;
	file = fopen(LINKEDLIST_FILE_NAME, "rb");
	if (file == NULL) {
		fprintf(stderr, "\n새 목록을 생성합니다.\n");
		writeLinkedList(getHead());
		return;
	}

	//파일에서 연결리스트를 불러온다 
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
		printf("\n저장할 파일 명을 입력해 주세요: ");
		scanf("%s", filename);
		if (!findFileName(filename)) break;
		else {
			system("cls");
			printf("중복되는 파일이 있습니다. 다른 파일명을 입력해주세요. \n\n");
			printf("------[저장할 내용]-------\n\n");
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


