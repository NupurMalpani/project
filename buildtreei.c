#include<string.h>

#include"buildtree.h"
char a[1] = "";
void initstore(table *tableobject) {
tableobject = (table*)malloc(sizeof(table)*256);
}
void store(node *parent, char *m,table *tableobject) {
		
		tableobject[parent->str].ch = parent->str;
		tableobject[parent->str].code = m;
}
void tree(node *parent, node *child,char *str,table *tableobject) {
	if(parent == NULL)
		return;
	strcat(a,str);
	if(parent->child_0== NULL && parent->child_1 == NULL) {
		store(parent,a,tableobject);
		a[0] = 0;	
	}
	else {
	tree(child, child->child_0, "0",tableobject);
	tree(child,child->child_1, "1",tableobject);
	}
}
table *assigntree(treelist *t) {
	table *tab;
	initstore(tab);
	node *root = t->head;
	tree(root, root->child_0, "0",tab);
	tree(root, root->child_1,"1",tab);
	return tab;
}
treelist *buildtree(list *l,treelist *t) {
	node *child_0,*child_1;
	while(l->head) {
		node *p = removal(l);
		node *q = removal(l);
			if( p && q) {
				node *tmp = (node*)malloc(sizeof(node));
				tmp->freq =  p->freq + q->freq;
				tmp->child_0 = p;
				tmp->child_1 = q;
				insert(l,tmp);
				insertintree(t,p);
				insertintree(t,q);
				insertintree(t,tmp);
				child_0 = p;
				child_1 = q;
			}
		else {
			node *tmp = (node*)malloc(sizeof(node));
			tmp->freq = p->freq;
			tmp->child_0 = child_0;
			tmp->child_1 = child_1;
			insertintree(t,tmp);
			
		}
	}
	return t;
}
