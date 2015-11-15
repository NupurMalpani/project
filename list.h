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
typedef struct node {
	char str;
	size_t freq;
	struct node *child_0;
	struct node *child_1;
	struct node *next;
}node;
typedef struct list {
	node *head;
	int length;
}list;
void init(list *l);
void insert(list *l,node *tmp);
node *removal(list *l);
void printlist(list l);
