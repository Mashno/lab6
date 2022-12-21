#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	char simbol;
	struct Node *next;
} Node;

void push_end(Node** head,Node** tail, int simbol)
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

/*int sort(Node** head, Node** tail)
{
	Node *tmp1 = *head;
	Node *tmp2 = *head;
	while(tmp1->next!=NULL)
	{
		while(tmp2->simbol)
		{
		}
		
	}
}*/

Node* find_tmp(Node *head, int space)
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
int main()
{
	while(1)
	{
		Node* head = NULL;
		Node* tail = NULL;
		int simbol;
		Node* tmp = NULL;
		printf("Введите вашу строку: ");
		int space = 0;
		while((simbol=getchar())==' ');
		push_end(&head, &tail, simbol);

		while((simbol=getchar())!='\n')
		{
			if(simbol == ' ')
			{
				space++;
			}
			
			if(simbol== ' ')
			{
				tmp = find_tmp(head, space);
				//sort(*tmp)
			}
			push_end(&head,&tail,simbol);
		}
		//здесь сделать ещё один сортi
		space++;
		tmp = find_tmp(head, space);
		//sort(tmp);

		/*while(tmp1->next!=NULL)
		{
			tmp1=tmp1->next;
			while(tmp2->simbol!=" ")
			{
				tmp2=tmp2->next;
			}
			sort(&tmp1, &tmp2);
			tmp1 = tmp2
		}*/
		//delete_last_space(head);//пробелы будут записываться в space, поэтому tmp будет указывать верно, тогда следует удалить все пробелы, если это пробел и слева от него пробел, а потом удалить последний элемент, если он пробел
		print_Node(head);
		free_Node(&head);
		if (getchar()==EOF)
		{
			return 0;
		}
	}
	return 0;
}
