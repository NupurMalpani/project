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
#include"bitlzwex1.h"
#include<string.h>
#include<math.h>
/*we have assumed the maximum redundancy to be not greater than 2000*/
char word[2000];
char element[2000];
char *concat(char *str,char x) {
	char *tmp = (char*)malloc(sizeof(char) * 2000);
	strcpy(tmp,str);
	int l = strlen(str);
	tmp[l] = x;
	tmp[l + 1] = '\0';
	return tmp;
}
int check(size_t f){
	int temp;
	char str[50];
	int i  = 0;
	while(i < 2 && f){
        	temp = f % 16;
      		//To convert integer into character
      		if( temp < 10)
          	 	temp =temp + '0';
      		else
        		 temp = temp + 'A' - 10;
	str[i++]= temp;
       f = f /16;
	}
	str[i] = '\0';
	if(strcmp(str,"FF") == 0)
		return 1;
	return 0;

}
size_t bsn(char  *m){
	int length = strlen(m);
	int i;
	//printf("%s",m);
	size_t sum = 0;
	for( i = (length - 1) ; i >= 0; i--){
		if(m[i] == '1')
			sum += pow(2,length - i -1);
	}
	return sum;
}
int flag4 = 0;
void convertback(FILE *fp,char *name){
	int index = 2;
	int tp = 16;/*power of 2 to check*/
	int i = 1;
	char c;
	char *buff =(char*) malloc(41);
	FILE *fr = fopen(name,"w");	

	strcpy(buff,"");
	int j;
	triex t;
	initlzw(&t);
	char *str;
	size_t token;
	size_t f = 256;
	while((c = getc(fp)) != EOF){
		for(j = 7; j >= 0; j--){
			if((c >> j) & 1)
				strcat(buff,"1");
			else
				strcat(buff,"0");
			
 		}
		
		if( i % index == 0){
			if((strcmp(buff,"1111111111111111") == 0) || (strcmp(buff,"111111111111111111111111") == 0) || 
							(strcmp(buff,"11111111111111111111111111111111") == 0)){
				i = 0;			
				index++;
			}
			else  {
				token = bsn(buff);
				//printf("%d\t",token);
				if(flag4 == 0){
				 	str = searchtriex(token,&t);
					//printf("%s",str);
			/*we are string copying instead of direct assigning cause we want the size of element to not change*/
					strcpy(element,str);
					fprintf(fr,"%s",element);
					strcpy(word,element);
					flag4 = 1;
				}
				else{
					str = searchtriex(token,&t);
					if(str == NULL) {
						strcpy(element,concat(word,word[0]));
					}
					else {
						strcpy(element,str);
					}
					//printf("%s",element);
					fprintf(fr,"%s",element);
					inserttriex(&t,f,concat(word,element[0]));
					strcpy(word,element);
					f++;
					//char str[256];
					//snprintf(str, sizeof( str), "%zu", f);
					//printf("%s",str);
					//printf("we were here %zx\n",f);
					if( (f == pow(2,tp) - 1) ){
						printf("we entered here tp was %zu",f);
						tp += 8;
						f++;
					}
					if( check(f)){
						f++;
					}
				}
				strcpy(buff,"");
			}
		}
		i++;
	
	}
	
	fclose(fp);

}
