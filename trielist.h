#include<stdlib.h>
typedef struct trienode {
    char key;
    unsigned int value;
    struct trienode *next;
    struct trienode *prev;
    struct trienode *children;
    struct trienode *parent;
}trienode;
typedef struct trienode *trielist;
void inittl(trielist *l);
void insertintl(trielist *l,char tmp,int f);
trienode *createnode(char key, unsigned int value);/*create a new node that doesn't point to anything*/
void printtl(trielist l);
