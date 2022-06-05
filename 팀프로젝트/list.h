#pragma once
typedef struct TEXTFILE {
	char data[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE];
}TEXTFILE; //한 파일에 담겨있는 정보

typedef TEXTFILE Element;
typedef struct LinkedNode {
	Element data;
	struct LinkedNode* link;
}Node; //각 파일을 연결한 연결리스트 

extern Node *head; //연결리스트의 헤드노드 


//노드에서 사용하는 함수 모음 
int is_empty();
void init_list();
Node* get_entry(int pos);
int size();
void replace(int pos, Element e);
void insert_next(Node *prev, Node *node);
void insert(int pos, Element val);//노드 삽입 
Node* remove_next(Node *prev);
void del(int pos);
void clear_list();
