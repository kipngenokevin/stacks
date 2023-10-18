#include "0-main.h"
/**
 * print - prints the values in the stack
 * @head: pointer to the head of the stack
 * Return: void
 */
void print(stack_t *head)
{
	while (head != NULL)
	{
		printf("%d ", head->n);
		head = head->next;
	}
	printf("\n");
}
