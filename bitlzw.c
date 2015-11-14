#include "bitlzw.h"
#include<string.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>
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
		if(i >= 16){
			if(temp[i] == '1') 
				tmp[2] |= (1 << (i - 16));
			else 			
				tmp[2] &= ~(1 << (i - 16));
		}
	}
	return tmp;
}
/*we store the codes in a bit array with size with a multiple of 8
accordingly we set or clear the bits ...initializing by 0 all the bits are cleared
converttocode decides how long the bitsize should be we assume the number is never greater than 16777215*/
code *converttocode(int number){
	static done = 0;
	static largest = 0;
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
		}
		
	}
	else{	
		done = 1;
		t->b = (char*)malloc(3);
		t->bits  = 24;	
	}
	t->b = setbits(number,t->bits);
	return t;		
} 
/*it reads the string of 16 bits till it encounters 65535 and then starts reading 24 bits and we have assumed the number wont go beyond   2^24 - 1 */

