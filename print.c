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
	stack_t *head = *stack;

	if (var.stack_len == 0)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
				lineNumber);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}
