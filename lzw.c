#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include <errno.h>
#include"trie.h"
#include<string.h>
#include"bitlzw.h"
char word[2000];
void rev(char *str){
	int i,j,c;
	for( i = 0, j = strlen(str) - 1; i < j; i++, j--){
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}

}
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
	rev(z);
	return z;
}

char *concat(char *str,char x) {
	char *tmp = (char*)malloc(sizeof(char) * 2000);
	strcpy(tmp,str);
	int l = strlen(str);
	tmp[l] = x;
	tmp[l + 1] = '\0';
	return tmp;
}
int main(int argc, char *argv[]) {
	static done = 0;
	char arr;
	char c[2];
	char x;
	char *mod;
	int n, z;
	trie t;
	code *cc;
	char *temp;
	inittrie(&t);
	result *l;
	int fd = open(argv[1], O_RDONLY);
	FILE *fr = fopen(argv[2], "w");	
	FILE *fm = fopen("dummy","w");
	//printf("%d",fd);
	if(fd == -1) {
		perror("fopen failed");
		return errno;
	}
	char h[2];
	h[1] = 255;
	h[0] = 255;
	strcpy(word,"");
	while((n = read(fd, &arr, 1))){
		//printf("(%c %d)\t",arr,fd);
		c[0] = arr;
		c[1] = '\0';
		mod = concat(word,arr);
		//printf("%s\n",c);
			if(present(mod,&t)){
				
				strcat(word,c);
				//printf("%s",word);
			}
			else{
				///printf("%s\n",word);
				result *l = searchintrie(word, &t);
				//if(l->d.value > 65535)
				//	putc(65535,fr);
				//if(l->found) 
				printf("%d\t",l->d.value);
				char *m = convert(l->d.value); 
				fwrite(m,sizeof(m),1,fm);
				char *y =" ";
				fwrite(y,sizeof(y),1,fm);
				cc = converttocode(l->d.value);
				z = (cc->bits)/ 8;
				temp = cc->b;
				while(z){
					z--;
					putc(temp[z],fr);
				
				}
				//printf("%s\n",concat(word,x));
				add(mod, &t);
				strcpy(word,c);
			}
						
	}
	close(fd);
	fclose(fr);	
	return 0;
}

