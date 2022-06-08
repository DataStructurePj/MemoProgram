#include "main.h"

Node* head = NULL;
int is_empty() {
	return head == NULL;
}
void init_list() {
	head = NULL;
}
Node* get_entry(int pos) {
	Node * p = head; //헤드 부터 시작 
	int i;
	for (i = 0; i < pos; i++, p = p->link)
		if (p == NULL)return NULL;
	return p;
}
int size() {
	Node *p;
	int count = 0;
	for (p = head; p != NULL; p = p->link)count++;
	return count;
}

//해당하는 파일 명을 찾는다. 
int find(char str[]) {
	Node *tmp = head;
	for (int i = 0; tmp != NULL; tmp = tmp->link)
	{
		if (strcmp(tmp->data, str))  return -1; //만약 같은 파일이 있는 경우, 다른 이름을 설정하도록 함. 
	}
	return 0;
}
void replace(int pos, Element e) {
	Node* node = get_entry(pos);
	if (node != NULL) strcpy(node->data, e);
}
void insert_next(Node *prev, Node *node) {
	if (node != NULL) {
		node->link = prev->link;
		prev->link = node;
	}
}
void insert(int pos, Element val) {
	Node *new_node, *prev;
	new_node = (Node*)malloc(sizeof(Node));
	strcpy(new_node->data,val);
	new_node->link = NULL; //새로운 노드와 연결할 부분  
	if (pos == 0) {
		new_node->link = head;
		head = new_node;
	}
	else {
		prev = get_entry(pos - 1);
		if (prev != NULL)insert_next(prev, new_node);
		else free(new_node);
	}
}
Node* remove_next(Node *prev) {
	Node* removed = prev->link;
	if (removed != NULL)prev->link = removed->link;
	return removed;
}
void del(int pos) {
	Node* prev, *removed;
	if (pos == 0 && is_empty() == 0) {
		removed = head;
		head = head->link;
		free(removed);
	}
	else {
		prev = get_entry(pos - 1);
		if (prev != NULL) {
			removed = remove_next(prev);
			free(removed);
		}
	}
}

Node *getHead() {
	return head;
}
void print_list() {
	Node *tmp;
	printf("파일 목록 : \n");
	for (tmp = head; tmp != NULL; tmp = tmp->link)
		printf("%s \n ", tmp->data);
	printf("\n");
}
void clear_list()
{
	while (size()) {
		del(size() - 1);
	}
}