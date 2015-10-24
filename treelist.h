#include<stdlib.h>
 #include"list.h"
typedef struct treelist{
	node*  head;
	int length;
}treelist;
void inittreelist(treelist *t);
void insertintree(treelist *t, node *tmp);
