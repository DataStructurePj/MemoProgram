//�������� ���� ���� �� ���� �ҷ������ ������ �����ϴ� �Լ��� �����ص� �������. 


// ���� ����� ������ ����� �����ش�. 
// ����� ������ �����ϸ� �ش� ������ �����ϴ� ȭ������ ��ȯ�Ѵ�.
int loadFileList();

void writeFile(char Data[][MAX_ARRAY_SIZE], char filename[]);
void readFile(char filename[], char contents[][MAX_ARRAY_SIZE]);

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