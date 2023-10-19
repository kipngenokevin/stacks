#include "monty.h"
/**
 * push - adds an element to the top of the stack
 * @stack: stack to be added on
 * @line_number: for printing out errors
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	printf("Inserted to stack instruction from line %d\n", line_number);
}
