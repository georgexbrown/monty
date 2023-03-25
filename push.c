#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the head of stack
 * @lineNumber: the line number currently being processed
 * Return: nothing
 */

void push(stack_t **stack, unsigned int lineNumber)
{
	int n, m = 0;

	if (prgctl.arg[0] == '-')
		m++;
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
 * pushStack - pushes a new node onto the top of the stack
 * @stack: double pointer to the top of the stack
 * @n: integer value to be added to the new node
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
 * pushQueue - pushes a new node onto the top of the queue
 * @queue: double pointer to the top of the stack
 * @n: integer value to be added to the new node
 * Return: nothing
 */
void pushQueue(stack_t **queue, int n)
{
	stack_t *newNode, *temp;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, " Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->next = NULL;

	if (*queue == NULL)
	{
		newNode->prev = NULL;
		*queue = newNode;
	}

	temp = *queue;
	while (temp->next)
		temp = temp->next;

	temp->next = newNode;
	newNode->prev = temp;

}

