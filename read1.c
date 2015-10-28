 
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include<unistd.h>
#include"buildtree.h"
#include"bitio.h"
#include<string.h>
int main(int argc, char *argv[]) {
	char arr;
	size_t *a = (size_t *)malloc(sizeof(size_t) * 257);
	int n, i,count = 0;
	int fd = open(argv[1], O_RDONLY);
	list l;
	table *tab = (table*)malloc(sizeof(table));
	init(&l);
	if(fd == -1) {
		perror("fopen failed");
		return errno;
	}
	for(i = 0; i < 257; i++){
		a[i] = 0;
	}
	while((n = read(fd, &arr, 1)))
		a[(int)arr]++;
	//a[256] = 1; 
	for( i = 1 ; i < 257 ; i++){
		if(a[i]){
			count++;
			//printf("%d -%ld\n", i, a[i]);
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
	//printlist(&l);
	node *treefinal = buildtree(&l);
	printf("after building the tree\n");
	tab = assigntree(treefinal);
	printf("after assigning the tree\n");
	
	/*BIT_FILE *outputfile = OpenOutputBitFile("output");
	 fd = open(argv[1], O_RDONLY);
	 char *str;
	count =0;
	 double s;
	 unsigned long m;
	while((n = read(fd, &arr, 1))){
		str = tab[(int)arr].code;
		 count = strlen(str);
		 s = atoi(str);
		 m = (unsigned long int)s;
		OutputBits(outputfile,m,count);
	}
	 str = tab[257].code;
	 count = strlen(str);
	s = atoi(str);
	m = (unsigned long int)s;
	OutputBits(outputfile,m,count);
	 CloseOutputBitFile(outputfile);
	close(fd);*/
	return 0;
}
