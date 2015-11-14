#include <stdio.h>
#include"trieex.h"
#include<string.h> /*size of level*/
void rev(char *str){
	int i,j,c;
	for( i = 0, j = strlen(str) - 1; i < j; i++, j--){
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}

}
void inittl(triex *l){
	*l = NULL;
}	
trienode* createnode(){
	int i = 0;
	trienode *z = (trienode*)malloc(sizeof(trienode));
    	for(i = 0;i < SIZE;i++)
        	z->children[i] = NULL;
    	z->value = NULL;
    	return z;
}
result converttostring(size_t key){
	size_t t = key;
	int i = 0;
	while(t){
		t = t /10;
		i++;
	}
	char *z = (char*)malloc(i + 1);
	i = 0;
	while(key){
		z[i] = key % 10 + '0';
		key = key /10;
		i++;
	}
	z[ i + 1] = '\0';
	rev(z);
	result m;
	m.str = z;
	m.level = i; 
	return m;
}
void inserttriex(triex *l,size_t key,char *value){
	int level = 0;
	int index;	
	result m = converttostring(key);
	int length = m.level;
	char *str = m.str;
	char *temp = (char*)malloc(strlen(value) + 1);
	strcpy(temp,value);
	if(*l == NULL)
		*l = createnode();
	trienode *prev = *l;
	for(;level < length; level++){
		index = str[level] - '0';
		if(prev->children[index] == NULL)
			prev->children[index] = createnode();
		prev = prev->children[index];
	}
	prev->value = temp;
}
void initlzw(triex *l){
	inittl(l);
	int i;
	char c[2];
	for(i = 0; i < 256 ; i++){
		c[0] = i;
		c[1] = '\0';
		inserttriex(l,i,c);
//		if((*l)[7].children)
//		printf("%u%d in here",&((*l)[7].children) , i);		 
	} 
}
/*we find the number of levels needed and convert it to string so that we can get a digit at a time*/
char *searchtriex(size_t key,triex *l){
	int level = 0;
	int index;	
	trienode *prev = *l;
	result m = converttostring(key);
	int length = m.level;
	char *str = m.str;
	for(;level < length; level++){
		index = str[level] - '0';
		if(prev->children[index])
			prev = prev->children[index];
		else
			break;
	}
	if(str[level] == '\0')
		return prev->value;
	return NULL; 
}
/*struct node *q = root;
    int length = strlen(key);
    int level = 0;
    for(;level < length;level++) {
        int index = key&#91;level&#93; - 'a';
        if(q->link[index] != NULL)
            q = q->link[index];
        else
            break;
    }
    if(key[level] == '\0' && q->data != -1)
        return q->data;
    return -1;
*/


