/*Copyright (C) 2015  Nupur Malpani
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trielist.h"
trienode *createnodetl(char key, unsigned int value){
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
	trienode *temp = createnodetl(tmp,f);
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
