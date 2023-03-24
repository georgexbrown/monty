#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top of stack
 * @stack:
 * @lineNumber:
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
