#include "monty.h"

/**
 * remove_comment - removes comments from a string
 * @str: the string to remove comments from
 */
void removeComment(char *commands)
{
    int i;

    for (i = 0; commands[i]; i++)
    {
        if (commands[i] == '#')
        {
            commands[i] = '\0';  /* replace '#' with null character */
            break;
        }
    }
}


/**
 * opQueue - switches to queue mode
 * @stack: pointer to top of stack
 * @lineNumber: line number of current operation
 */
void opQueue(stack_t **stack, unsigned int lineNumber)
{
	(void)*stack;
	(void)lineNumber;
	prgctl.mode = 1;
}


/**
 * opStack - switches to stack mode
 * @stack: pointer to top of stack
 * @lineNumber: line number of current operation
 */
void opStack(stack_t **stack, unsigned int lineNumber)
{
        (void)*stack;
        (void)lineNumber;
        prgctl.mode = 0;
}
