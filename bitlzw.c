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
#include "bitlzw.h"
#include<string.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
int flag = 0;
/*converts the number to binary and passes the string*/
char *nsb(int number,int bits){
		char *c =(char*)malloc(bits + 1);
		int i = 0;
		while(number){
			if( number % 2 == 1)
				c[i] = '1';
			else
				c[i] = '0';
			number = number / 2;
			i++;
		}
		for( ; i < bits; i++)
			c[i] = '0';
		c[bits] = '\0';
		return c;
}
/*converts a binary string to number*/

/*sets the number in bits number of bits*/
char *setbits(int number, int bits){
	char *temp = nsb(number,bits);
	int n = bits / 8;
	char *tmp = (char *)malloc(n);
	int i;		
	for( i = 0; i < n; i++)
		tmp[i] = 0;
	for( i = 0; i <bits; i++)
	{
		if( i < 8){
			if(temp[i] == '1') 
				tmp[0] |= (1 << (i));
			else 			
				tmp[0] &= ~(1 << (i));
	
	
		}
		if(i > 7 && i < 16){
			if(temp[i] == '1') 
				tmp[1] |= (1 << (i - 8));
			else 			
				tmp[1] &= ~(1 << (i - 8));
		}
		if(i >= 16 && i < 24){
			if(temp[i] == '1') 
				tmp[2] |= (1 << (i - 16));
			else 			
				tmp[2] &= ~(1 << (i - 16));
		}
		if(i > 24){
			if(temp[i] == '1') 
				tmp[3] |= (1 << (i - 24));
			else 			
				tmp[3] &= ~(1 << (i - 24));

		}
	}
	return tmp;
}
/*we store the codes in a bit array with size with a multiple of 8
accordingly we set or clear the bits ...initializing by 0 all the bits are cleared
converttocode decides how long the bitsize should be we assume the number is never greater than 16777215*/
code *converttocode(int number){
	static done = 0;
	code *t = (code*)malloc(sizeof(code));	
	if(number < 65535) {
		switch(done) {
			case 0:
				t->b = (char *)malloc(2);
				t->bits = 16;
				break;
			case 1:
				t->b = (char*)malloc(3);
				t->bits = 24;
				break;
			case 2:
				t->b = (char*)malloc(4);
				t->bits  = 32;	
				break;
			case 3:
				t->b = (char*)malloc(5);
				t->bits  = 40;			
				break;
		}
		
	}
	else if(number > 65535 && number < 16777215){
		if(flag == 0){	/*the first time it comes in this function only then do done = 1*/
			done = 1;
			flag = 1;
		}
		switch(done){
			case 1:
				t->b = (char*)malloc(3);
				t->bits  = 24;
				break;
			case 2:
				t->b = (char*)malloc(4);
				t->bits  = 32;	
				break;
			case 3:
				t->b = (char*)malloc(5);
				t->bits  = 40;			
				break;
		}	
	}
	else if(number > 16777215 && number < 4294967295){
		if(flag == 1 ){/*the first time it comes in this function only then do done = 2*/
			flag = 2;
			done = 2;

		}
		switch(done){
			case 2:				
				t->b = (char*)malloc(4);
				t->bits  = 32;	
			case 3:
				t->b = (char*)malloc(5);
				t->bits  = 40;	


		}
	}
	else{
		done = 3;
		t->b = (char*)malloc(5);
		t->bits  = 40;	

	}	
	t->b = setbits(number,t->bits);
	return t;		
} 
/*it reads the string of 16 bits till it encounters 65535 and then starts reading 24 bits and we have assumed the number wont go beyond   2^40 - 1 */

