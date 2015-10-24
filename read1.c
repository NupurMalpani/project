/* This is a program which reads a string from a text file 
third in a set of three programs which do the same work
*/
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include<unistd.h>
#include"buildtree.h"
#include"bitio.h"
#include<string.h>
int main(int argc, char *argv[]) {
	char arr;
	size_t *a = (size_t *)malloc(sizeof(size_t) * 256);
	int n, i,count = 0;
	int fd = open(argv[1], O_RDONLY);
	list l;
	treelist t;
	inittreelist(&t);
	init(&l);
	if(fd == -1) {
		perror("fopen failed");
		return errno;
	}
	for(i = 0; i < 256; i++){
		a[i] = 0;
	}
	while((n = read(fd, &arr, 1)))
		a[(int)arr]++; 
	for( i = 0 ; i < 256 ; i++){
		if(a[i]){
			count++;
			node *tmp = (node*)malloc(sizeof(node));
			tmp->freq = a[i];
			tmp->str = i;
			tmp->child_0= NULL;
			tmp->child_1 = NULL;
			insert(&l,tmp);
		}
	}
	
	close(fd);
	free(a);
	treelist *treefinal = buildtree(&l,&t);
	table *tab = assigntree(treefinal);
	BIT_FILE *outputfile = OpenOutputBitFile("output");
	 fd = open(argv[1], O_RDONLY);
	while((n = read(fd, &arr, 1))){
		char *str = tab[arr].code;
		int count = strlen(str);
		double s = atoi(str);
		unsigned long m = (unsigned long int)s;
		OutputBits(outputfile,m,count);
	}
	
	close(fd);
	return 0;
}
