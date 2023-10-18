#include <stdio.h>
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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop}
	};
	int i, line_no, opcode_found = 0;
	int size_of_instruction = sizeof(instructions) / sizeof(instructions[0]);
	stack_t *stack = NULL;

	/* Function that loops throug the file to find opcode and line numbers */
	/* on obtaining opcode, pass it to the necessary function */
	for (i = 0; i < size_of_instruction; i++)
	{
		if (strcmp(opcode, instructions[i].opcode == 0))
		{
			instructions[i].f(&stack, line_no);
			opcode_found = 1;
			break;
		}
	}
	if (!opcode_found)
	{
		fprintf(stderr, "L<line_number>: unknown instruction <opcode>\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
