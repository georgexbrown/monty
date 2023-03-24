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


/**
 * nop - Doesn’t do anything.
 * @stack: A pointer to the head of the stack_t list.
 * @lineNumber: The line number of the opcode.
 */
void nop(stack_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
}


/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the head of the stack_t list.
 * @lineNumber: The line number of the opcode.
 */
void rotl(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	(void)lineNumber;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;

		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}


/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the head of the stack_t list.
 * @lineNumber: The line number of the opcode.
 */
void rotr(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	(void)lineNumber;

	if (*stack && (*stack)->next)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;

		temp->prev->next = NULL;
		temp->next = *stack;
		temp->prev = NULL;
		(*stack)->prev = temp;
		*stack = temp;
	}
}
