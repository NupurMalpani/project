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
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#define SIZEX 10
typedef struct triexnode {
	char* value;
	struct triexnode* children[SIZEX];
 }triexnode;
typedef struct resultx{
	char *str;
	int level;
}resultx;
typedef struct triexnode *triex;
void inittlx(triex *l);
void inserttriex(triex *l,size_t key,char *value);
char *searchtriex(size_t key, triex *l);
void initlzw(triex *l);



