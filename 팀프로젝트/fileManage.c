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
	char *tmp = malloc(sizeof(char) * 100);
	sprintf(tmp, "%s%s.txt", DATA_DIR, filename);
	file = fopen(tmp, "r");
	int idx = 0;
	if (file == NULL) {
		fprintf(stderr, "\n파일을 열 수 없습니다.\n");
		exit(1);
	}
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	fread(contents, sizeof(char), size, file);
	free(tmp);
	fclose(file);
}

//현재 연결리스트에 저장되어있는 데이터 목록을 출력한다. 
void printNow(char data[][MAX_ARRAY_SIZE]) {
	int CURSORX = 0;
	int CURSORY = 4;
	int i = 0;
	int len = 0;
	for (i = 0; data[i][0] != '\0'; i++) {
		gotoxy(CURSORX, CURSORY++);
		printf("%s\n", data[i]);
		len = i > 0 ? strlen(data[i]) - 1 : strlen(data[i]);
	}
	gotoxy(CURSORX + len, i > 0 ? CURSORY - 1 : CURSORY);
}


//데이터를 저장한다. 
void writeData(int idx, char data[][MAX_ARRAY_SIZE], char *fn) {
	char text[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
	int line = 0;
	char mode;
	char cmp; int index = 0;
	memset(text, '\0', sizeof(text));

	//만약 파일 불러오기 이후, 해당 파일을 수정하려는 경우,
	if (data != NULL) {
		for (int i = 0; data[i][0] != '\0'; i++) {
			strcpy(text[i], data[i]);
			index = strlen(data[i]);
			line++;
		}
		line-=1; //마지막에 line이 1 증가한 상태로 for문이 종료되므로 ,-1해줌. 
	}

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
				if (cmp == '\r' || index == MAX_ARRAY_SIZE - 1 && b == 0) {
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
				else if (cmp != -32) {
					text[line][index] = cmp;
					index++;
				}
			}
			break;
		case 'p':
			if (index != 0) {
				gotoxy(0, 2);
				printf("_______________________저장할 내용_____________________\n");
				printNow(text);
				printf("\n_______________________________________________________\n\n");
				int ret = showAlert("저장하시겠습니까?", 1);

				//저장을 원하는 경우 동작
				if (ret == 1) {
					defineFileName(fn, text, line, idx);
					writeLinkedList(getHead());
					return;
				}
				//저장을 원하지 않는 경우 
				else if (ret == 2) return;
			}
			//저장할 데이터가 없는 경우 
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
		case ESC: //ESC를 누르면 종료 
			return;
		}
	}
}


//파일에 연결리스트를 작성한다. 
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
		if (resultC == 0) break; //더이상 불러올 데이터가 없는 경우 루프를 종료 
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


void defineFileName(char *filename, char text[][MAX_ARRAY_SIZE], int line, int idx) {
	char *fn = malloc(sizeof(char) * 100); //파일명 
	memset(fn, 0, sizeof(char) * 100);
	if (filename != NULL)strcpy(fn, filename);
	printf("\n--------------------------------------");
	while (1) {
		printf("\n저장할 파일 명을 입력해 주세요: \n");
		if (filename != NULL)printf("(이전 파일명: %s) ", fn);
		scanf("%s", fn);
		int retFInd = findFileName(fn);
		if (retFInd == -1) {
			writeFile(text, fn);
			if (filename != NULL) 
				replace(idx, fn);
			else 
				insert(idx, fn);
			free(fn);
			return;
		}
		else {
			if (filename != NULL) {
				writeFile(text, fn);
				replace(retFInd, fn);
				return;
			}
			else {
				system("cls");
				printf("중복되는 파일이 있습니다. 다른 파일명을 입력해주세요. \n\n");
				printf("---------------------------------[저장할 내용]------------------------------\n\n");
				printNow(text);
				printf("\n----------------------------------------------------------------------------\n");
			}
		}
	}
}


