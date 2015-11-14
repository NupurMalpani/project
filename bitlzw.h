#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

typedef struct code{
	char *b;/*array for bit array*/
	int bits;
}code;
void rev(char *str);
char *nsb(int number,int bits);
char *setbits(int number, int bits);
code *converttocode(int number);

