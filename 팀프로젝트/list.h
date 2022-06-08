#pragma once
typedef struct TEXTFILE {
	char filename[MAX_ARRAY_SIZE];
	int passwd;
}TEXTFILE; //한 파일에 담겨있는 정보

typedef char* Element;

//각 파일을 연결한 연결리스트 
typedef struct LinkedNode {
	Element data[100]; //메모 파일 
	struct LinkedNode* link; //다음 노드를 가리키는 포인터 
}Node; 


//연결리스트의 헤드노드 
//extern Node *head; 

//노드에서 사용하는 함수 모음 

//연결리스트가 비어있는지 확인하는 함수 
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
Node *getHead();


void print_list();