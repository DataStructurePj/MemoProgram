#pragma once
#include "main.h"
typedef struct TEXTFILE {
	char filename[MAX_ARRAY_SIZE];
    char *passwd; //비밀번호  
}TEXTFILE; //한 파일에 담겨있는 정보

typedef char* Element;

//각 파일을 연결한 연결리스트 
typedef struct LinkedNode {
	Element data[MAX_ARRAY_SIZE]; //메모 파일 
	struct LinkedNode* link; //다음 노드를 가리키는 포인터 
}Node; 

//노드에서 사용하는 함수 모음 

//연결리스트가 비어있는지 확인하는 함수 
int is_empty();
//연결리스트를 초기화 하는 함수 
void init_list();
//연결리스트의 특정부분의 값을 가져오는 함수 
Node* get_entry(int pos);
//연결리스트의 사이즈를 가져오는 함수
int size();
//연결리스트의 값을 변경하는 함수 
void replace(int pos, Element e);
//연결리스트의 특정노드 다음에 노드를 삽입하는 함수 
void insert_next(Node *prev, Node *node);
void insert(int pos, Element val);//노드 삽입 
//연결리스트의 특정노드 다음에 있는 노드를 지우는 함수 
Node* remove_next(Node *prev);
void del(int pos);
int findFileName(char str[]);
void clear_list();
//
Node *getHead();


void print_list();