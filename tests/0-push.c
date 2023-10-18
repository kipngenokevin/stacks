#include "0-main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * push - adds an item on top of a linked list
 * @num: integer added on top of a list
 * Return: void
 */
void push(int num, stack_t **head)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
}
