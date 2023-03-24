#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the head of stack
 * @lineNumber: the line number currently being processed
 * Return: nothing
 */

void push(stack_t **stack, unsigned int lineNumber)
{
	int n;

	/* check if arg to be pushed is NULL */
	if (!prgctl.arg || !isdigit(prgctl.arg[0]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", lineNumber);
		exit(EXIT_FAILURE);
	}
	
	n = atoi(prgctl.arg);
	if (prgctl.mode == 0)
		pushStack(stack, n);
	else
		pushQueue(stack, n);
}

/**
 * pushStack - 
 * @stack:
 * @n:
 * Return: nothing
 */
void pushStack(stack_t **stack, int n)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, " Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *stack;
	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}

/**
 * pushQueue - 
 * @stack:
 * @n:
 * Return: nothing
 */
void pushQueue(stack_t **stack, int n)
{
	(void)*stack;
	(void)n;
/*	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, " Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

*/}
