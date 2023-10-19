#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
int num;
/**
 * main - receives file inputs from a .m file
 * @argc: intger count of the arguments passed
 * @argv: array of strings passed
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
	};
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_no = 1;
	stack_t *stack = NULL;
	int size_of_instruction = sizeof(instructions) / sizeof(instructions[0]);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		pass_line(line, &stack, instructions, size_of_instruction, line_no);
		line_no++;
	}
	if (line)
		free(line);
	fclose(file);
	return (0);
}
/**
 * pass_line - function that passes the line from file
 * @line: line passed
 * @stack: pointer to the stack
 * @line_no: number of the line accoding to file
 * @inst: array of instruction
 * @size: size of the array of instruction
 * Return: void
 */
void pass_line(char *line, stack_t **stack,
		instruction_t *inst, int size, unsigned int line_no)
{
	char *del = " \n";
	char *token = strtok(line, del);
	int token_index = 1;
	char *opcode = NULL;
	int i, opcode_found = 0;


	while (token != NULL)
	{
		if (token_index == 1)
			opcode = strdup(token);
		else if (strcmp(opcode, "push") == 0 && token_index == 2)
			num = is_int(token, line_no);
		token = strtok(NULL, del);
		token_index++;
	}
	for (i = 0; i < size; i++)
	{
		if (strcmp(opcode, inst[i].opcode) == 0)
		{
			inst[i].f(stack, line_no);
			opcode_found = 1;
			break;
		}
	}
	if (!opcode_found)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_no, opcode);
		exit(EXIT_FAILURE);
	}
	if (opcode != NULL)
		free(opcode);
}
/**
 * is_int - checks whether the token is integer
 * @token: pointer to the token
 * @line_no: line number in the file
 * Return: int if it is integer, exit otherwise
 */
int is_int(char *token, unsigned int line_no)
{
	int value = atoi(token);

	if (value == 0 && token[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}
	return (value);
}
