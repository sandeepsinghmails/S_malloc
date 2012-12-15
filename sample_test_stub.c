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

/* Note: 
 * sample_test_stub.c is a Test Stub written primarily to explain how to link the
 * S_malloc Library with any Separate Project's Source Code
 */

#include <stdlib.h>

/* Code Change for Integration with S_malloc Library Starts */
extern void add_allocated_node 			(void *address, int size);
extern void remove_allocated_node	 	(void *key_address);
/* Code Change for Integration with S_malloc Library Ends */

void* wrapper_malloc (int size)
{
	void *ptr = malloc(sizeof(size));
	
	/* Code Change for Integration with S_malloc Library Starts */
	add_allocated_node (ptr, size);
	/* Code Change for Integration with S_malloc Library Ends */

	return ptr;
}

void wrapper_free (void *ptr)
{
	/* Code Change for Integration with S_malloc Library Starts */
	remove_allocated_node (ptr);
	/* Code Change for Integration with S_malloc Library Ends */

	free (ptr);
}

int main()
{
	int* ptr[4];
	int counter = 0;

	for (counter=0; counter<4; counter++)
	{
		ptr[counter] = wrapper_malloc(sizeof(int)*(counter+1));
	}

	/* Free an allocated Memory */
	wrapper_free (ptr[1]);

	return 0;
}

