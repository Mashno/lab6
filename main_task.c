#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	char simbol;
	struct Node *next;
} Node;
void push_end(Node** head,Node** tail, char simbol)
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
	printf("\"");
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
int main()
{
	while(1)
	{
		Node* head = NULL;
		Node* tail = NULL;
		char simbol;
		printf("Введите вашу строку: ");

		while((simbol=getchar())!='\n')
		{
			push_end(&head,&tail,simbol);
			
		}
		print_Node(head);
		free_Node(&head);
	}
	return 0;
}
