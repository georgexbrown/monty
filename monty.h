#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE
#define BUFSIZE 1024

/* Libraries */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int lineNumber);
} instruction_t;

/**
 * struct progcontrol_s - interpreter control
 * @mode: interpreter mode (stack/queue)
 * @arg: argument passed with push opcode
 * @content: content of __ (unused)
 */
typedef struct progcontrol_s
{
	int mode;
	char *arg;
	char *content;
} progcontrol_t;

/* Prototypes */
extern int (*opFunctions[])(char **);
extern progcontrol_t prgctl;

int executeOpcode(char *commands, stack_t **stack, unsigned int lineNumber);
void freeAll(void);
void freeStack(stack_t **stack);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void removeComment(char *commands);

/* Opcode Functions */
void push(stack_t **stack, unsigned int lineNumber);
void pushStack(stack_t **stack, int n);
void pushQueue(stack_t **queue, int n);
void pall(stack_t **stack, unsigned int lineNumber);
void pint(stack_t **stack, unsigned int lineNumber);
void pop(stack_t **stack, unsigned int lineNumber);
void swap(stack_t **stack, unsigned int lineNumber);
void add(stack_t **stack, unsigned int lineNumber);
void nop(stack_t **stack, unsigned int lineNumber);
void sub(stack_t **stack, unsigned int lineNumber);
void divi(stack_t **stack, unsigned int lineNumber);
void mul(stack_t **stack, unsigned int lineNumber);
void mod(stack_t **stack, unsigned int lineNumber);
void pchar(stack_t **stack, unsigned int lineNumber);
void pstr(stack_t **stack, unsigned int lineNumber);
void rotl(stack_t **stack, unsigned int lineNumber);
void rotr(stack_t **stack, unsigned int lineNumber);
void opQueue(stack_t **stack, unsigned int lineNumber);
void opStack(stack_t **stack, unsigned int lineNumber);

#endif /* _MONTY_H_ */
