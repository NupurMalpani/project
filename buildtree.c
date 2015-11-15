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
#include<string.h>
#include<stdio.h>
#include"buildtree.h"
#include<stdlib.h>
size_t size = 1000;
char *a;
char **b;
#define MAX(a,b) ((a)>(b)?(a):(b))
int depth(node *root) {
	if(root == NULL)
		return 0;
	return 1 + MAX(depth(root->child_0),depth(root->child_1));
}
void store(node *parent, char *m,table *tableobject){
		int index;		
		if(parent->str == -1)
			index = 256;
		else
			index = (int)parent->str;
		if(index == 256)
			printf("eof %s\n",m);
		tableobject[index].ch = parent->str;
		tableobject[index].code = m;
}

table *assigntree(node *root,int length) {
	int i;
	a = (char*)malloc(sizeof(char) * length);
	b = (char **)malloc(sizeof(char*) * 257);
	for(i = 0; i < 257; i++) {
			b[i] = (char*)calloc(1,length);
			}
	table *tab = (table*)malloc(sizeof(table) * 257);
	traverse(root, tab, 0); 
	return tab;
}
void traverse(node *parent, table *tab,int top){
	int index;
	if(parent->child_0 == NULL && parent->child_1 == NULL) {
		a[top] = '\0';
		//printf("%s %c %zu \n",a, parent->str,parent->freq);
		if(parent->str == -1)
			index = 256;
		else
			index = (int)parent->str;
		strcpy(b[index],a);
		store(parent,b[index],tab);
		top--;
		return;
	}
	if(parent->child_0) {
		a[top] = '0';
		traverse(parent->child_0,tab, top + 1);
	}
	if(parent->child_1) {
		a[top] = '1';
		traverse(parent->child_1,tab ,top + 1);
		}
	top--;
}
void preorder(node *root) {
	if(!root)
		return;
	printf("%d %zx\n", root->str,root->freq);
	preorder(root->child_0);
	preorder(root->child_1);
}
node *buildtree(list *l) {
	node *child_0,*child_1;
	size_t count = 0;
	size_t count1 = 0;
	size_t i;
	node **tmp = (node **)malloc(sizeof(node*) * size);
	for( i  = 0; i <size ; i++)
		tmp[i] = (node*)malloc(sizeof(node)); 
	node *tmp1 = (node *)malloc(sizeof(node));
	while(l->length){
		node *p ;
		p = removal(l);
		node *q;
		q = removal(l);
			if( p && q) {
				
				(tmp[count])->freq =  p->freq + q->freq;	
				(tmp[count])->child_0 = p;
				(tmp[count])->child_1 = q;
				insert(l,tmp[count]);
				child_0 = p;
				child_1 = q;
				printlist(*l);
				count++;
				
			}
		else {
			tmp1->freq = p->freq;
			tmp1->child_0 = child_0;
			tmp1->child_1 = child_1;
			insert(l,tmp1);
			break;
		}
	}
	return tmp1;
}
