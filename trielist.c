#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trielist.h"
trienode *createnode(char key, unsigned int value){
	trienode *new = (trienode*)malloc(sizeof(trienode));
	new->key = key;
	new->value = value;
	new->parent = NULL;
	new->children = NULL;
	new->next = NULL;
	new->prev = NULL;
	return new;
}
void inittl(trielist *l) {
	*l = NULL;
}
void insertintl(trielist *l, char tmp,int f) {
	trienode *p;
	trienode *temp = createnode(tmp,f);
	if(*l == NULL) {
		*l = temp;
		//tmp->next = NULL;
		//tmp->prev = NULL;
	}
	else{	/*inserting at the head of the list*/
		if((*l)->key > tmp){
			p = *l;
			*l = temp;		
			//temp->parent = p->parent;
			temp->next = p;
			p->prev = temp;
		}
		else{
			/*inserting in the list*/
			p = *l;
			while(p->next && (p->next->key < tmp))
				p = p->next;
				temp->next = p->next;
				temp->prev = p;
				p->next  = temp;		
		}	
	}
}
/* can insert at positions [0..length] */
void printtl(trielist l) {
	trienode *p;
	p = l;
	while(p) {
		printf("(%c %d) ",p->key,p->value);
		p = p->next;
	}
	printf("\n");
}
