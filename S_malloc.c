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

#include "S_malloc.h"

FILE *fptr;
static ListNode *head;

void add_allocated_node (void *address, int size)
{
	ListNode *temp 		= NULL;

	if (NULL==head)
	{
		/* Insert the First Node */
		 head = malloc(sizeof(ListNode));
		(head)->memsize = size;
		(head)->memaddress = address;
		(head)->next = NULL;
	}
	else
	{
		temp = head;

		/* Traverse the List to Find Out Empty Position */
		while (temp->next!=NULL)
		{
			temp=temp->next;
		}

		temp->next = malloc(sizeof(ListNode));
		if (temp->next == NULL)
		{
			printf ("\nMemory Allocation Failure !\n");
			exit (EXIT_FAILURE);
		}
		(temp->next)->memsize 		= size;
		(temp->next)->memaddress	= address;
		(temp->next)->next 		 	= NULL;
	}
	
	/* Print the Linked List To File */
	print_nodelist_to_file ();
}

void remove_allocated_node (void *key_address)
{
	ListNode	*temp 		= NULL;
	ListNode	*deletenode = NULL;

	/* Check if List Is Empty */
	if (NULL==head)
	{
		return;
	}

	/* Check if Head Node contains the Key Address */
	if ((head)->memaddress == key_address)
	{
			deletenode = head;
			head = (head)->next;
			free(deletenode);
			deletenode = NULL;
	}
	/* Head doesn't Have the Key Address */
	else
	{
		/* Search for the Node with Matching Address */
		temp = head;
	
		while (temp->next != NULL)
		{
			if ((temp->next)->memaddress == key_address)
			{
				deletenode = temp->next;
				temp->next = (temp->next)->next;
				free (deletenode);
				deletenode = NULL;
				break;
			}
			temp = temp->next;
		}
	
		/* Last Node */
		if (temp->memaddress == key_address)
		{
			free (temp);
		}
	}

	/* Print the Linked List To File */
	print_nodelist_to_file ();
}

void print_nodelist_to_file ()
{
	ListNode *temp = head;

	fptr = fopen ("S_malloc_logs.txt", "w");
	if (NULL==fptr)
	{
		printf ("\nFailure: Cannot Open Log-File for Writing\n\n");
		exit (EXIT_FAILURE);
	}

	while (temp)
	{
		fprintf (fptr, "\nHeap Memory Address: %ld, Size = %d Bytes\n", (long)temp->memaddress, temp->memsize);

		temp = temp->next;
	}

	fclose (fptr);
}


