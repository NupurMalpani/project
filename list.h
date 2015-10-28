#include<stdlib.h>
typedef struct node {
	char str;
	size_t freq;
	struct node *child_0;
	struct node *child_1;
	struct node *next;
}node;
typedef struct list {
	node *head;
	int length;
}list;
void init(list *l);
void insert(list *l,node *tmp);
node *removal(list *l);
void printlist(list l);
