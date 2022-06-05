#pragma once
typedef struct TEXTFILE {
	char data[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
}TEXTFILE; //�� ���Ͽ� ����ִ� ����

typedef TEXTFILE Element;
typedef struct LinkedNode {
	Element data;
	struct LinkedNode* link;
}Node; //�� ������ ������ ���Ḯ��Ʈ 

extern Node *head; //���Ḯ��Ʈ�� ����� 


//��忡�� ����ϴ� �Լ� ���� 
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
