/* 
 * Author: Sandeep Singh
 * Date  : Dec 14, 2012
 * 
 * Copyright 2012 Sandeep Singh (sandeepsinghmails@gmail.com)
 *
 * This file is part of S_malloc Library.
 * Fragmentation Remover is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * S_malloc Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with S_malloc Library. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _S_MALLOC_H
#define _S_MALLOC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	void	 	*memaddress;
	int 	 	memsize;	
	struct node *next;
} ListNode;

void add_allocated_node 		(void *address, int size);
void remove_allocated_node_node (void *key_address);
void print_nodelist_to_file 	();

#endif
