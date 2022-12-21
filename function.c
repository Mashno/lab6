#include <stdio.h>
#include <stdlib.h>
#include "function.h"
void push_node_end(Node** head,Node** tail, int simbol)
{
	if((*head) == NULL)
	{
		Node* tmp = (Node*) malloc(sizeof(Node));
		tmp->simbol = simbol;
		tmp->next = NULL;
		*head = tmp;
		*tail = tmp;
	}
	else
	{
 	        Node* tmp = (Node*)malloc(sizeof(Node));
	        tmp->simbol = simbol;
	        tmp->next = NULL;
	        (*tail) ->next=tmp ;
	        *tail = tmp;
	}
}

void print_Node(Node* head)
{
	printf("Итоговая строка: \"");
	Node* current = head;
	while(current)
	{
		printf("%c", current->simbol);
		current = current->next;
	}
	printf("\"\n");
}

void free_Node(Node** head)
{
	Node* previos = NULL;
	while((*head)->next)
	{
		previos = (*head);
		(*head) = (*head)->next;
		free(previos);
	}
	free(*head);
}

void sort(Node* start_word)
{
	int swapped, i;
	Node* ptr1;
	Node* lptr = NULL;
	do
	{
		swapped = 0;
		ptr1 = start_word;

		while(ptr1->next != lptr)
		{
			if(ptr1->simbol > ptr1->next->simbol)
			{
				int tmp = ptr1->simbol;
				ptr1->simbol = ptr1->next->simbol;
				ptr1->next->simbol = tmp;
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	while(swapped !=0);
}

Node* find_start_word(Node *head, int space)
{
	if(space == 1)
	{
		return head;
	}
	for(int i = 0; i<space-1;)
	{
		if(head->simbol==' ')
		{
			i++;
		}
		head = head->next;
	}
	return head;
}

Node* delete_last_space(Node* start_word)
{
	Node*previous = NULL;
	while(start_word->next)
	{
		previous = start_word;
		start_word = start_word->next;
	}
	free(start_word);
	previous->next = NULL;
	return previous;
}

