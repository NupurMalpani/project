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
typedef struct trienode {
    char key;
    unsigned int value;
    struct trienode *next;
    struct trienode *prev;
    struct trienode *children;
    struct trienode *parent;
}trienode;
typedef struct trienode *trielist;
void inittl(trielist *l);
void insertintl(trielist *l,char tmp,int f);
trienode *createnodetl(char key, unsigned int value);/*create a new node that doesn't point to anything*/
void printtl(trielist l);
