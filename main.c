#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * main - receives file inputs from a .m file
 * @argc: intger count of the arguments passed
 * @argv: array of strings passed
 * Return: 0 success
 */
int num;
int main(int argc, char **argv)
{
	instruction_t instructions[] = {
		{"push", push},
	};
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_no = 1;
	int size_of_instruction = sizeof(instructions) / sizeof(instructions[0]);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		pass_line(line, instructions, size_of_instruction, line_no);
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
 * @line_no: number of the line accoding to file
 * @inst: array of instruction
 * @size: size of the array of instruction
 * Return: void
 */
void pass_line(char *line, instruction_t *inst, int size, unsigned int line_no)
{
	char *del = " ";
	char *token = strtok(line, del);
	int token_index = 1;
	char *opcode = NULL;
	int i, opcode_found = 0;
	stack_t *stack = NULL;


	while (token != NULL)
	{
		if (token_index == 1)
			opcode = strdup(token);
		else if (token_index == 2)
			num = atoi(token);
		token = strtok(NULL, del);
		token_index++;
	}
	printf("Opcode: %s\n", opcode);
	for (i = 0; i < size; i++)
	{
		if (strcmp(opcode, inst[i].opcode) == 0)
		{
			inst[i].f(&stack, line_no);
			opcode_found = 1;
			break;
		}
	}
	if (!opcode_found)
	{
		fprintf(stderr, "L<%u>: unknown instruction <%s>\n", line_no, opcode);
		exit(EXIT_FAILURE);
	}
	if (strcmp(opcode, "push") == 0)
		printf("num: %d\n", num);
	if (opcode != NULL)
		free(opcode);
}
