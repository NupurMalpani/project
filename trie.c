#include<stdlib.h>
#include"trie.h"
int count = 257;
trienode *createnode(char key, unsigned int value) {
	trienode *new = (trienode*)malloc(sizeof(trienode));
	new->key = key;
	new->value = value;
	new->parent = NULL;
	new->children = NULL;
	new->next = NULL;
	new->prev = NULL;
	return new;
}
void trieinit(trielist *root){
	int i;
	for( i = 0; i < 256; i++) {
		root->tl[i].child = NULL;
		root->tl[i].key =(char) i;
		root->tl[i].value = i + 1;	
	}
}
void insert(char *str, int length, trielist *root){
		char a = str[0];
		char b = str[1];
		trienode *tmp = createnode(b,count);
		tmp->parent = root->tl[int(a)];
		

		
}
	
