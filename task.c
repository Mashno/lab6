#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main()
{
	while(1)
	{
		Node* head = NULL;
		Node* tail = NULL;
		int simbol;
		Node* start_word = NULL;
		int space = 0;

		printf("Введите вашу строку: ");
		while((simbol=getchar())==' ');//пропускаем первые пробелы
		if(simbol =='\n')
		{
			printf("\"\"\n");
			continue;
		}
	        push_node_end(&head, &tail, simbol);

		while((simbol=getchar())!='\n')
		{
			if((tail->simbol == ' ')&&(simbol==' '))//если второй подряд пробел, то пропускаем его
			{
				continue;
			}
			if(simbol == ' ')
			{
				space++;
			}
			
			if(simbol== ' ')
			{
				start_word = find_start_word(head, space);//указатель на начало слова
				sort(start_word);
			}
			push_node_end(&head,&tail,simbol);
		}

	        if(tail->simbol==' ')//удаляем последний пробел
		{
			start_word = find_start_word(head, space);
			tail = delete_last_space(start_word);
			space--;
		}	
		space++;
		start_word = find_start_word(head, space);//указатель на начало последнего слова строки
		sort(start_word);

	        print_Node(head);
		free_Node(&head);
		if (getchar()==EOF)
		{
			return 0;
		}
	}
	return 0;
}
