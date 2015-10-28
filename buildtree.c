#include<string.h>
#include<stdio.h>
#include"buildtree.h"
char a[1000] = "";
size_t size = 1000;
void store(node *parent, char *m,table *tableobject) {
		
		tableobject[(int)parent->str].ch = parent->str;
		tableobject[(int)parent->str].code = m;
}
void tree(node *parent, node *child,char *str,table *tableobject) {
	if(parent == NULL)
		return;
	strcat(a,str);
	if(parent->child_0 == NULL && parent->child_1 == NULL) {
		store(parent,a,tableobject);
		a[0] = 0;	
	}
	else {
	tree(child, child->child_0, "0", tableobject);
	tree(child, child->child_1, "1", tableobject);
	}
}
table *assigntree(node *t) {
	table *tab = (table*)malloc(sizeof(table) * 256);
	node *root = t;
	printf("%zu\n", root->freq);
	tree(root, root->child_0, "0",tab);
	tree(root, root->child_1, "1",tab);
	return tab;
}
node *buildtree(list *l) {
	node *child_0,*child_1;
	size_t count = 0;
	size_t i;
	node **tmp = (node **)malloc(sizeof(node*) * size);
	for( i  = 0; i <size ; i++)
		tmp[i] = (node*)malloc(sizeof(node)); 
	node *tmp1 = (node *)malloc(sizeof(node));
	printlist(*l);
	while(l->length){
		node *p ;
		p = removal(l);
		node *q;
		q = removal(l);
		//printf("we reached here\n");
			if( p && q) {
				printf("p->str =  %d, p->freq = %zu\n", p->str, p->freq);
				printf("q->str =  %d, q->freq = %zu\n", q->str, q->freq);
				//if(p->freq > 1)
					//printf("we reached %lu",count);
				
				(tmp[count])->freq =  p->freq + q->freq;	
				(tmp[count])->child_0 = p;
				(tmp[count])->child_1 = q;
				insert(l,tmp[count]);
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
	//printf("%zu",tmp1->freq);
	return tmp1;
}
