#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include <errno.h>
#include<string.h>
#include"bitlzwex1.h"
int main(int argc, char *argv[]){
	
	FILE *fp= fopen(argv[1], "r");
	convertback(fp,argv[2]);
}
