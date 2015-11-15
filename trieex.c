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
#include <stdio.h>
#include"trieex.h"
#include<string.h> /*size of level*/
void reverse(char *str){
	int i,j,c;
	for( i = 0, j = strlen(str) - 1; i < j; i++, j--){
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}

}
void inittlx(triex *l){
	*l = NULL;
}	
triexnode* createnodex(){
	int i = 0;
	triexnode *z = (triexnode*)malloc(sizeof(triexnode));
    	for(i = 0;i < SIZEX;i++)
        	z->children[i] = NULL;
    	z->value = NULL;
    	return z;
}
resultx converttostring(size_t key){
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
	reverse(z);
	resultx m;
	m.str = z;
	m.level = i; 
	return m;
}
void inserttriex(triex *l,size_t key,char *value){
	int level = 0;
	int index;	
	resultx m = converttostring(key);
	int length = m.level;
	char *str = m.str;
	char *temp = (char*)malloc(strlen(value) + 1);
	strcpy(temp,value);
	if(*l == NULL)
		*l = createnodex();
	triexnode *prev = *l;
	for(;level < length; level++){
		index = str[level] - '0';
		if(prev->children[index] == NULL)
			prev->children[index] = createnodex();
		prev = prev->children[index];
	}
	prev->value = temp;
}
void initlzw(triex *l){
	inittlx(l);
	int i;
	char c[2];
	for(i = 0; i < 256 ; i++){
		c[0] = i;
		c[1] = '\0';
		inserttriex(l,i,c);
		 
	} 
}
/*we find the number of levels needed and convert it to string so that we can get a digit at a time*/
char *searchtriex(size_t key,triex *l){
	int level = 0;
	int index;	
	triexnode *prev = *l;
	resultx m = converttostring(key);
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



