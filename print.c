#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top of stack
 * @stack: deouble pointer to top of stack
 * @lineNumber: line number of current working operation
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	(void)lineNumber;
	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - print value on top of `stack', or exit if stack is empty
 * @stack: double pointer to head of stack
 * @lineNumber: line number of current operation
 *
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int lineNumber)
{

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
				lineNumber);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


/**
 * pchar - Prints the ASCII value of the top element of the stack
 * @stack: The stack
 * @lineNumber: The current line number in the file
 */
void pchar(stack_t **stack, unsigned int lineNumber)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				lineNumber);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: The stack
 * @lineNumber: The current line number in the file
 */
void pstr(stack_t **stack, unsigned int lineNumber)
{
	stack_t *current = *stack;

	while (current != NULL && current->n > 0 && current->n < 128)
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
