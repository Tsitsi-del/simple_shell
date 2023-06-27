#include "main.h"

/**
 * new_lineremoved - func to remove new line
 * @s: the string to remove newline
 */

void new_lineremoved(char *s)
{
	int index = 0;

	while (s[index] != '\0')
	{
		if (s[index] == '\n')
		{
			s[index] = '\0';
			break;
		}
		index++;
	}
}
