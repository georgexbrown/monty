#include "monty.h"

/**
 * freeStack - 
 * @head:
 *
 * Return: nothing
 */

void freeStack(stack_t **stack)
{
	stack_t *temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = temp;
	}
}
