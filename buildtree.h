#include"list.h"
typedef struct table {
	char ch;
	char *code;
}table;
void store(node *parent, char *m,table *tableobject);
void tree(node *parent, node *child,char *str,table *tableobject);
table *assigntree(node *t);
node *buildtree(list *l);
