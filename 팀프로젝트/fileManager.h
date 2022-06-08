//전반적인 파일 생성 및 파일 불러오기등 파일을 관리하는 함수를 선언해둔 헤더파일. 

//문장을 작성하는 함수 
//void writeStc(char Data[][MAX_ARRAY_SIZE]);

// 현재 저장된 파일의 목록을 보여준다. 
// 저장된 파일을 선택하면 해당 파일을 수정하는 화면으로 전환한다.
int loadFileList();

void writeFile(char Data[][MAX_ARRAY_SIZE], char filename[]);
void readFile(char filename[], char contents[][MAX_ARRAY_SIZE]);

//파일에 작성된 연결리스트를 불러오는 함수 
void readLinkedList();

//파일에 연결리스트를 작성하는 함수 
void writeLinkedList(Node *head);

//메모파일을 담을 디렉토리 생성 
void makeMemoDir();