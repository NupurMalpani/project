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
#include<stdio.h>
#include"trie.h"
#include<string.h>
#include<math.h>
/*checks for similarity with end of file that is if last 2 are FF */
int checkforeof(size_t f){
	int temp;
	char str[3];
	int i  = 0;
	while(i < 2 && f){
        	temp = f % 16;
      		//To convert integer into character
      		if( temp < 10)
          	 	temp =temp + '0';
      		else
        		 temp = temp + 'A' - 10;
		str[i++]= temp;
      		 f = f /16;
	}
	str[2] = '\0';
	if(strcmp(str,"FF") == 0)
		return 1;
	return 0;

}
void add(char *tn,trie *t){
	static int f = 256;
	result *m;
	int i, k, l, n;
	int j = strlen(tn);
	int index = 9;
	m = searchintrie(tn,t);/*returns the last matched element or found in case it is found*/
	trielist **tl;
	trielist **tlnew;
	if(m == NULL){
		printf("fatal error");
		return;
	}	
	if(m->found == 0){
		 if(m->d.last->children == NULL) {/*this is the first time we found the children of this node*/
			i = j - m->level;
			tl = (trielist**)malloc(sizeof(trielist*) * (i));
			for(k = 0; k < i; k++) {
				tl[k] = (trielist*)malloc(sizeof(trielist));
				inittl(tl[k]);
				insertintl(tl[k],tn[m->level + k], f);/*go on adding list to list levelwise*/
				if( k == 0) {
					m->d.last->children = *tl[0];/*make the trie point to the first list*/
					(*tl[0])->parent = m->d.last;
		
				}
				else {
					(*tl[k - 1])->children = (*tl[k]);/*make the list point to another list*/
					(*tl[k])->parent = (*tl[k - 1]); 
				}		
				f++;
				if( f == (pow(2,index) - 1)){
					f++;
					index++;

				}
				if(checkforeof(f)){
					//printf("we were here and we ensured this doesn't take place %d" ,f);
					f++;
				}
			}	
	
		}
		else{	/*children of the last node exist so we have to insert the next unmatching in the list of this parent and create 
			new lists for the remaining characters*/
			l = j - m->level - 1;
			tlnew = (trielist**)malloc(sizeof(trielist*) * (l));
			insertintl(&m->d.last->children,tn[m->level],f);
			f++;
			if(checkforeof(f)){

					//printf("we were here and we ensured this doesn't take place %d" ,f);
					f++;
				}	
			trienode *curr;
			for(curr = m->d.last->children; ((curr != NULL) && (curr->key <= tn[m->level])); curr = curr->next) {
				if(curr->key == tn[m->level]) {
					break;
				}
			}
			for(k = 0; k < l; k++) {
				tlnew[k] = (trielist*)malloc(sizeof(trielist));
				inittl(tlnew[k]);
				insertintl(tlnew[k],tn[m->level + k], f);
				if( k == 0) {
					curr->children = *tlnew[0];
					(*tlnew[0])->parent = curr; 
				}
				else {
					(*tlnew[k - 1])->children = (*tlnew[k]);
					(*tlnew[k])->parent = (*tlnew[k - 1]); 
				}		
				f++;
				if( f == (pow(2,index) - 1)){
					f++;
					index += 8;

				}
				if(checkforeof(f)){

					//printf("we were here and we ensured this doesn't take place %d" ,f);
					f++;
				}	
			}	
		}		

	}
	else if(m->found){
		printf("already present with value %c\n",m->d.value);
	}
}

void inittrie(trie *t){
	/*t = (trielist*)malloc(sizeof(trielist));*/
	int i;
	trielist tl;
	inittl(&tl);
	for( i = 0; i < 256; i++){
		insertintl(&tl,i,i);
	}
	*t = tl;
}
result s;
void printtrie(trie t){
		

}
/*search in tree if not found returns the address of last node matched*/
result *searchintrie(char *m, trie *t){
		trienode *last, *curr;
		trienode *level = *t;
		int j = strlen(m);		
		int i = 0;
		while(1){
			for(curr = level; ((curr != NULL) && (curr->key <= m[i])); curr = curr->next) {
				if(curr->key == m[i]) {
					last = curr;
					//printf("in search %c %s\n",m[i],m);
					break;
				}
			}
			if((curr == NULL) || (curr->key > m[i])) {
				s.found = 0;
				s.level = i;
				s.d.last = last;
				return &s;
			}
			if(m[i + 1] == '\0') {
				s.found = 1;
				s.d.value = last->value;
				s.level = i + 1;
				return &s;
				
			}

			level = curr->children;
			i++;
		}
		return NULL;
}
int present(char *m,trie *t){
	result *l = searchintrie(m,t);
		if(l->found)
			return 1;
	return 0;
}
