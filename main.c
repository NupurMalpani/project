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
#include "compress.h"
#include<unistd.h>
#include "decompress.h"
#include<stdio.h>
#include"lzw.h"
#include"lzwrev.h"
int main(int argc, char *argv[]){
	//printf("we were here\n");
	int choice;
	char filename[200];
	char outputfile[200];
	while(1){
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf(" 				Data Compression and Decompression for text files\n");
		printf("--------------------------------------------------------------------------------------------------------\n");  
		printf("1.LZW COMPRESSION\n");
		printf("2.LZW DECOMPRESSION\n");
		printf("3.HUFFMAN COMPRESSION\n");
		printf("4.EXIT\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter absolute path of filename if not in current directory to be compressed and the name of output compressed file:\n");
				scanf("%s %s",filename,outputfile);
				lzw(filename,outputfile);	
				printf("Compressed Successfully...\n");
				break;

			case 2:
				printf("enter absolute path of compressed filename if not in current directory and filename for decompressed file:\n");		
				scanf("%s %s",outputfile,filename);
				lzwrev(outputfile,filename);
				printf("Decompressed Successfully...\n");
				break;
			case 3:
				printf("enter absolute path of filename if not in current directory:\n");
				scanf("%s",filename);
				compress(filename);
				printf("Compressed Successfully...\n");
				break;
			case 4:
				return 0;

		}
	}
		return 0;
}


	 
