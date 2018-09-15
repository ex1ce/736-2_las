include<stdio.h> 
#include<stdlib.h> 

typedef struct _Node { 
	int value; 
	struct _Node *next; 
	struct _Node *prev; 
} Node; 


typedef struct _List { 
	int size; 
	Node *head; 
	Node *tail; 
} List;

void push(List *list, int val) { 
	Node *new_node = (Node*) malloc(sizeof(Node)); 
	if (new_node == NULL) { 
		return; 
	} 
	new_node->value = val; 
	new_node->next = NULL; 
	new_node->prev = list->tail; 
	if (list->tail) { 
		list->tail->next = new_node; 
	} 
	list->tail = new_node; 
	if (list->head == NULL) { 
		list->head = new_node; 
	} 
	list->size++; 
} 

int pop(List *list) {
	Node *elm = NULL;
	int tmp;
	elm = list->head;
	if (elm == NULL) {
		exit(5);
	}
	if (elm->prev) {
		elm->prev->next = elm->next;
	}
	if (elm->next) {
		elm->next->prev = elm->prev;
	}
	tmp = elm->value;
	if (!elm->prev) {
		list->head = elm->next;
	}
	if (!elm->next) {
		list->tail = elm->prev;
	}
	free(elm);
	list->size--;
	return tmp;
}

void print(List *list) { 
	Node *tmp = list->head; 
	while (tmp) { 
		printf("%d ", tmp->value); 
		tmp = tmp->next; 
	} 
	printf("\n"); 
} 

int main() {
	List *list = (List*) malloc(sizeof(List));
	list->size = 0;
	list->head = list->tail = NULL;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int val;
		scanf ("%d", &val);
		push(list, val);
		print(list);
	}
	for(int i = 0; i < n; i++) {
		pop(list);
		print(list);
	}
}
