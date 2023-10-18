#include "0-main.h"
/**
 * pop - gets the element stored at the head pointer
 * @head: pointer to pointer of the head
 * Return: n
 */
int pop(stack_t **head)
{
	stack_t *current;
	int n;

	if (*head == NULL)
	{
		fprintf(stderr, "Error: stack is empty\n");
		exit(EXIT_FAILURE);
	}
	current = *head;
	n = current->n;
	*head = current->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(current);
	return (n);
}
