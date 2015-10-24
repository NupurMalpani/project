#include"treelist.h"
void inittreelist(treelist *t){
	t->head = NULL;
	t->length = 0;
}
void insertintree(treelist *t, node *tmp){
	if(t->head) {
		tmp->next = t->head;
		t->head = tmp;
	}
	else
		t->head = tmp;
	t->length++;
}
