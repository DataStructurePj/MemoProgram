#pragma once
#include "main.h"
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

//��忡�� ����ϴ� �Լ� ���� 

//���Ḯ��Ʈ�� ����ִ��� Ȯ���ϴ� �Լ� 
int is_empty();
//���Ḯ��Ʈ�� �ʱ�ȭ �ϴ� �Լ� 
void init_list();
//���Ḯ��Ʈ�� Ư���κ��� ���� �������� �Լ� 
Node* get_entry(int pos);
//���Ḯ��Ʈ�� ����� �������� �Լ�
int size();
//���Ḯ��Ʈ�� ���� �����ϴ� �Լ� 
void replace(int pos, Element e);
//���Ḯ��Ʈ�� Ư����� ������ ��带 �����ϴ� �Լ� 
void insert_next(Node *prev, Node *node);
void insert(int pos, Element val);//��� ���� 
//���Ḯ��Ʈ�� Ư����� ������ �ִ� ��帤
Node* remove_next(Node *prev);
void del(int pos);
int findFileName(char str[]);
void clear_list();
Node *getHead();


void print_list();