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
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include"compress.h"
#include<fcntl.h>
void createdictionaryfile(table *tab) {
	FILE *fp = fopen("dictionary.txt", "w");
	int i;
	for( i = 0; i < 257; i++) {
		if(tab[i].code != NULL){
				fprintf(fp,"%d  %s\n",i,tab[i].code);
		}
	}
	fclose(fp);
}
void compress(char *filename) {	
	char arr;
	size_t *a = (size_t *)malloc(sizeof(size_t) * 257);
	int n, i,count = 0;
	int fd = open(filename, O_RDONLY);
	list l;
	table *tab;
	init(&l);
	if(fd == -1) {
		perror("fopen failed");
	}
	for(i = 0; i < 257; i++){
		a[i] = 0;
	}
	while((n = read(fd, &arr, 1)))
		a[(int)arr]++;
	a[256] = 1; 
	for( i = 0 ; i < 257 ; i++){
		if(a[i]){
			count++;
			//printf("%d -%ld\n", i, a[i]);
			node *tmp = (node*)malloc(sizeof(node));
			tmp->freq = a[i];
			if( i == 256)
				tmp->str = -1;
			else
				tmp->str = i;
			tmp->child_0= NULL;
			tmp->child_1 = NULL;
			insert(&l,tmp);
		}
	}
	close(fd);
	free(a);
	//printlist(&l);
	
	node *root = buildtree(&l);
	printf("after building the tree\n");
	if(root == NULL)
		return;
	preorder(root);
	int count2 = depth(root);
	printf("%d\n",count2);
	 tab= assigntree(root, count2 + 1);
	printf("after assigning the tree\n");
	createdictionaryfile(tab);
	BIT_FILE *outputfile = OpenOutputBitFile("huffmancompressed");
	 fd = open(filename, O_RDONLY);
	 char *str;
	 size_t s;
	int length = 0;
	 unsigned long m;
	//for( i = 0 ; i <57; i++)
	//	printf("%s %d\n",tab[i].code,i);
	while((n = read(fd, &arr, 1))){
		//printf("%c",arr);
		str = tab[(int)arr].code;
		printf("%s %d %c\n",str,arr,arr);
		 s = atoi(str);
		OutputBits(outputfile,s,strlen(str));
	}
	//printf("we at least exited the read loop");
	OutputBits(outputfile,atoi(tab[256].code),strlen(tab[256].code));
	CloseOutputBitFile(outputfile);
	system("mkdir huffmanfolder");
	system("mv dictionary.txt huffmanfolder");
	system("mv huffmancompressed huffmanfolder");
	close(fd);

}
/*read the table and create the file accordingly*/

