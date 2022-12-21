#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char simbol;
	struct Node *next;
} Node;

void push_node_end(Node** head,Node** tail, int simbol);

void print_Node(Node* head);

void free_Node(Node** head);

void sort(Node* start_word);

Node* find_start_word(Node *head, int space);

Node* delete_last_space(Node* start_word);
