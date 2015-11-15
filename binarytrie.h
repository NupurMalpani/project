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
/*binary trie implementation using array for huffman coding*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SIZE 2
typedef struct btrienode {
	int value;
	struct btrienode* children[SIZE];
 }btrienode;
typedef struct btrienode *btrie;
void initbt(btrie *l);
void insertbt(btrie *l,char *key,int value);
int searchbt(char* key,btrie *l);

