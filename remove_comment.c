#include "monty.h"

/**
 * remove_comment - removes comments from a string
 * @str: the string to remove comments from
 */
void removeComment(char *commands)
{
    int i;

    for (i = 0; str[i]; i++)
    {
        if (str[i] == '#')
        {
            str[i] = '\0';  /* replace '#' with null character */
            break;
        }
    }
}
