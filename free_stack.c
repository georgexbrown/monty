#include "monty.h"

/**
 * freeStack - frees all elements of a stack_t stack
 * @stack: pointer to the top (stack) or bottom (queue) of the stack*
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
