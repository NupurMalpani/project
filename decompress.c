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
#include "decompress.h"
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

/*read the keys and values from a dictionary file and output accordingly using binarytrie*/
void decompress(char *folder){
	btrie n; 
	initbt(&n);
	int z;
	FILE *fr2, *fw;
	
	chdir(folder);
	
	fr2 = fopen("dictionary.txt","r");
	fw = fopen("decompressed.txt","w");
	int  value;
	char key[514];
	char dummy[514];
	int i;
	while(1){
		fscanf(fr2," %d", &value);
		fscanf(fr2,"%s",key);
		printf("value is %c stirn is %s\n",value, key);
		if(value != 256) {
			insertbt(&n,key,value);
		}
		else{
			insertbt(&n,key,i);
			break;
		}
	}
	BIT_FILE *fr1;
	fr1 = OpenInputBitFile("huffmancompressed");	
	int m;
	for(;;){
		key[0] = InputBit(fr1);
		key[1] = 0;
		while((m = searchbt(key,&n)) == -2){
			if(InputBit(fr1)){
				strcat(key,"1");
				
			}
			else {
				strcat(key,"0");
			}
		}
		printf("%s\n",key);	
		if( m  == -1)
			break;
		printf("%c",m);
		fprintf(fw,"%c",m);
	}
	CloseInputBitFile(fr1);
	fclose(fr2);
	fclose(fw);

	
}
