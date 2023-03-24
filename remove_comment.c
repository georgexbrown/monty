#include "monty.h"

/**
 * removeComment - 
 *
 */
void removeComment(char *line)
{
	/* finding the first occurrence of '#' as a comment */
	char *comment = strchr(line, '#');

	/* replacing the '#'  with a null terminator if not NULL */
	if (!comment)
		*comment = '\0';
}
