#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 *
 * @stack: Double pointer to the stack
 * @lineNumber: Line number of the operation
 */
void swap(stack_t **stack, unsigned int lineNumber)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			lineNumber);
		freeStack(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
