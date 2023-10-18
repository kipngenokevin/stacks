#include "0-main.h"
#include <stdio.h>
/**
 * main - implememnts push and pop from stack
 * Return: 0 success
 */
int main(void)
{
	stack_t *head = NULL;

	push(9, &head);
	push(10, &head);
	push(11, &head);
	push(12, &head);
	push(14, &head);
	print(head);
	pop(&head);
	print(head);
	return (0);
}
