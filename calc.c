#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @lineNumber: Number of the line in the file being executed
 */
void add(stack_t **stack, unsigned int lineNumber)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, lineNumber);
}

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the beginning of the stack
 * @lineNumber: Number of the line in the file being executed
 */
void sub(stack_t **stack, unsigned int lineNumber)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, lineNumber);
}


/**
 * mul - Multiplies the top two elements of the stack
 * @stack: Double pointer to the beginning of the stack
 * @lineNumber: Number of the line in the file being executed
 */
void mul(stack_t **stack, unsigned int lineNumber)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, lineNumber);
}

/**
 * divide - Divides the second top element of the stack by the top element
 * @stack: Double pointer to the beginning of the stack
 * @lineNumber: Number of the line in the file being executed
 */
void divi(stack_t **stack, unsigned int lineNumber)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, lineNumber);
}

/**
 * mod - Computes the remainder of the division of the second top element of
 * the stack by the top element
 * @stack: Double pointer to the beginning of the stack
 * @lineNumber: Number of the line in the file being executed
 */
void mod(stack_t **stack, unsigned int lineNumber)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, lineNumber);
}
