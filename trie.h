#include"trielist.h"
typedef struct result{
	union data{
		trienode* last;
		int value;
	}d;
	int found;
	int level;
}result;
typedef struct trienode *trie;

void add(char *tn,trie *t);/*given  a node insert in the trie*/
void inittrie(trie *t);/*intialize a trie*/
void printtrie(trie t);/*prints it levelwise*/
result *searchintrie(char *m, trie *root);/*search in tree if not found returns the address of last node matched*/
int present(char *m,trie *t);
