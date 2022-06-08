#pragma once
typedef struct TEXTFILE {
	char filename[MAX_ARRAY_SIZE];
	int passwd;
}TEXTFILE; //�� ���Ͽ� ����ִ� ����

typedef char* Element;

//�� ������ ������ ���Ḯ��Ʈ 
typedef struct LinkedNode {
	Element data[100]; //�޸� ���� 
	struct LinkedNode* link; //���� ��带 ����Ű�� ������ 
}Node; 


//���Ḯ��Ʈ�� ����� 
//extern Node *head; 

//��忡�� ����ϴ� �Լ� ���� 

//���Ḯ��Ʈ�� ����ִ��� Ȯ���ϴ� �Լ� 
int is_empty();
void init_list();
Node* get_entry(int pos);
int size();
void replace(int pos, Element e);
void insert_next(Node *prev, Node *node);
void insert(int pos, Element val);//��� ���� 
Node* remove_next(Node *prev);
void del(int pos);
void clear_list();
Node *getHead();


void print_list();