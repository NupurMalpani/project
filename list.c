#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void init(list *l) {
	l->head = NULL;
	l->length = 0;
}
void insertnode(list *l, node* tmp, int pos) {
	node *p;
	int i;
	if(pos < 0 || pos > l->length)		
		return;

	if(l->head == NULL) {
		l->head = tmp;
		tmp->next = NULL;
		l->length = 1;
		return;
	}
	if(pos == 0) {
		p = l->head;
		l->head = tmp;
		tmp->next = p;
		(l->length)++;
		return;
	}/* assert: posoitin is =>0 && <= length */
	p = l->head;
	for(i = 0; i < pos - 1; i++)
		p = p->next;	
	tmp->next = p->next;
	p->next = tmp;
	(l->length)++;
	return;
}
int search(list *l, int freq) {
		node *p;
		int pos = 0;
		p = l->head;
		while(p!= NULL && (p->freq < freq)){
			p =  p->next;
			pos++;
		}
		return pos;
}
void insert(list *l,node *tmp){
		if(l->head == NULL){
			insertnode(l, tmp, 0);
			}
		else{ 
			int pos = search(l, tmp->freq);
			insertnode(l,tmp,pos);
		}
}
node *removal(list *l) {
	node *p = l->head;
	if(l->head)
		l->head = l->head->next;
	return p;
	
}
/* can insert at positions [0..length] */
