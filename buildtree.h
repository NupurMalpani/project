#include"treelist.h"
typedef struct table {
	char ch;
	char *code;
}table;
void initstore(table *tableobject);
void store(node *parent, char *m,table *tableobject);
void tree(node *parent, node *child,char *str,table *tableobject);
table *assigntree(treelist *t);
treelist *buildtree(list *l,treelist *t);
