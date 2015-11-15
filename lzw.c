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
#include "lzw.h"
char word[2000];
void srev(char *str){
	int i,j,c;
	for( i = 0, j = strlen(str) - 1; i < j; i++, j--){
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}

}
int flag1 = 0;
char *convert(size_t key){	
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
	srev(z);
	return z;
}

char *concate(char *str,char x) {
	char *tmp = (char*)malloc(sizeof(char) * 2000);
	strcpy(tmp,str);
	int l = strlen(str);
	tmp[l] = x;
	tmp[l + 1] = '\0';
	return tmp;
}
void lzw(char *filename, char *outputfile) {
	static done = 0;
	char arr;
	char c[2];
	char x;
	char *mod;
	int n, z ,i;
	trie t;
	code *cc;
	char *temp;
	inittrie(&t);
	result *l;
	int fd = open(filename, O_RDONLY);
	FILE *fr = fopen(outputfile, "w");	

	//printf("%d",fd);
	if(fd == -1) {
		perror("fopen failed");
		//return errno;
	}
	char h[2];
	h[1] = 255;
	h[0] = 255;
	strcpy(word,"");
	size_t largest = 0;
	while((n = read(fd, &arr, 1))){
		//printf("(%c %d)\t",arr,fd);
		c[0] = arr;
		c[1] = '\0';
		mod = concate(word,arr);
		//printf("%s\n",c);
			if(present(mod,&t)){
				
				strcat(word,c);
				//printf("%s",word);
			}
			else{
				///printf("%s\n",word);
				
				result *l = searchintrie(word, &t);
				if(l->d.value > largest)
					largest = l->d.value;/*we keep a record of the largest encoded number*/
				if(largest > 65535 && flag1 == 0){
				/*the first time we get a number beyond 65535, insert 65535 start reading 24 bits*/
					for( i = 0;i < 2; i++)
						putc(h[0],fr);	
				}
				if(largest > 16777215 && flag1 == 1) {
					/*the first time we get a number beyond 16777215, insert 65535 start reading 24 bits*/
					for( i = 0; i < 3 ; i++)
						putc(h[0],fr);
					flag1 = 2;
				} 
				if(largest > 4294967295 && flag1 == 2) {
					/*the first time we get a number beyond 4294967295, insert 65535 start reading 24 bits*/
					for( i = 0; i < 4 ; i++)
						putc(h[0],fr);
					flag1 = 3;
				} 
				//if(l->found) 
				//printf("%d\t",l->d.value);
				cc = converttocode(l->d.value);
				z = (cc->bits)/ 8;
				temp = cc->b;
				while(z){
					z--;
					putc(temp[z],fr);
				
				}
				//printf("%s\n",concat(word,x));
				add(mod, &t);/*add new entry to dictionary*/
				strcpy(word,c);
			}
						
	}
	close(fd);
	fclose(fr);	
}

