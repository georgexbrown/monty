#include "monty.h"

/**
 * executeOpcode - check opcode against valid opcodes
 * @commands: opcode passed (to check)
 * @stack: pointer to head of stack
 * @lineNumber: number of line currently working on
 *
 * Return: 1 on error, 0 on success
 */
int executeOpcode(char *commands, stack_t **stack, unsigned int lineNumber)
{
	unsigned int i;

	/* opcode and it's function.. {opcode, f(...)} */
	instruction_t opFunction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", opQueue},
		{"stack", opStack},
		{NULL, NULL}
	};

	/* check if command isn't NULL */
	if (!commands[0])
	{
		fprintf(stderr, "No opcode to be interpreted!\n");
		exit(EXIT_FAILURE);
	}

	/* loop through opcodes to compare with commands passed */
	for (i = 0; opFunction[i].opcode; i++)
	{
		if (strcmp(commands, opFunction[i].opcode) == 0)
		{
			if (strcmp(commands, "stack") == 0)
			{
				prgctl.mode = 0;
			}
			else if (strcmp(commands, "queue") == 0)
			{
				prgctl.mode = 1;
			}
			else
			{
				opFunction[i].f(stack, lineNumber);
				return (0);
			}
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, commands);
	exit(EXIT_FAILURE);
	return (1);
}
