/*/*Copyright (C) 2015  Nupur Malpani
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
#include"binarytrie.h"
#include<string.h> 
void initbt(btrie *l){
	*l = NULL;
}	
btrienode* createnodebt(){
	int i = 0;
	btrienode *z = (btrienode*)malloc(sizeof(btrienode));
    	for(i = 0;i < SIZE;i++)
        	z->children[i] = NULL;
    	z->value = -3;
    	return z;
}
void insertbt(btrie *l,char *key,int value){
	int level = 0;
	int index;	
	int length = strlen(key);
	char *str = key;
	if(*l == NULL)
		*l = createnodebt();
	btrienode *prev = *l;
	for(;level < length; level++){
		index = str[level] - '0';
		if(prev->children[index] == NULL)
			prev->children[index] = createnodebt();
		prev = prev->children[index];
	}
	prev->value = value;
}
/*we find the number of levels needed and convert it to string so that we can get a digit at a time*/
int searchbt(char* key, btrie *l){
	int level = 0;
	int index;	
	btrienode *prev = *l;
	int length = strlen(key);
	char *str = key;
	for(;level < length; level++){
		index = str[level] - '0';
		if(prev->children[index])
			prev = prev->children[index];
		else
			break;
	}
	if(str[level] == '\0')
		return prev->value;
	return -2; 
}



