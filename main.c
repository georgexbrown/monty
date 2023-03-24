#define _GNU_SOURCE

#include <stdio.h>
#include "monty.h"

progcontrol_t prgctl = {0, NULL, NULL};

/**
 * main Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: Always Success (EXIT_SUCCESS)
 */
int main(int argc, char *argv[])
{
	FILE *montyFile = NULL;	/* file to be opened */
	char *lineContent = malloc(BUFSIZE);	/* stores content of file per line */
	char *commands = NULL;	/* stores tokenized file content */
	size_t len = BUFSIZE;		/* */
	stack_t *stack = NULL;	/* struct for performing operations */
	unsigned int lineCounter = 0;	/* stores line number of content */

	/* check if file to be read is greater or lesser than 1 */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* opening file passed in read-only mode but printing error if empty*/
	montyFile = fopen(argv[1], "r");
	if (!montyFile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* looping to get text contents of each line in file */
	while (getline(&lineContent, &len, montyFile) != -1)
	{
		commands = strtok(lineContent, " \n\t");  /*tokenize contents*/
	/*	removeComment(commands);   function that removes comment */
		prgctl.arg = strtok(NULL, " \n\t");
		lineCounter++;

		/* check 'commands' isn't empty so as to execute */
		if (commands[0])
		{
			if (executeOpcode(commands, &stack, lineCounter) == 1)
			{
				free(commands);
				freeStack(&stack);
				fclose(montyFile);
				exit(EXIT_FAILURE);
			}
		}
		prgctl.arg = NULL;
	}
	free(lineContent);
	freeStack(&stack);
	fclose(montyFile);
	exit(EXIT_SUCCESS);
}
