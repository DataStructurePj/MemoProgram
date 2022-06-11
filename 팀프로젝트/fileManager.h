//�������� ���� ���� �� ���� �ҷ������ ������ �����ϴ� �Լ��� �����ص� �������. 
#define CURSORX 0
#define CURSORY 4
#define ESC 27



// ���� ����� ������ ����� �����ش�. 
// ����� ������ �����ϸ� �ش� ������ �����ϴ� ȭ������ ��ȯ�Ѵ�.
int loadFileList();


void defineFileName(char *filename, char text[][MAX_ARRAY_SIZE], int line, int idx);
void writeFile(char Data[][MAX_ARRAY_SIZE], char filename[]);
void readFile(char filename[], char contents[][MAX_ARRAY_SIZE]);
void removeFile(char filename[], char passwd[]);
//���Ͽ� �ۼ��� ���Ḯ��Ʈ�� �ҷ����� �Լ� 
void readLinkedList();

//���Ͽ� ���Ḯ��Ʈ�� �ۼ��ϴ� �Լ� 
void writeLinkedList(Node *head);

//�޸������� ���� ���丮 ���� 
void makeMemoDir();


//�������� ����
void saveSetting(int col,int line, int color);

//�������� �ҷ�����
void loadSetting();