#include "main.h"

/**
 * rdcmd - function that reads commands
 * Return: returns the command
 */
char *rdcmd()
{
	char chr, *buf;
	size_t len = 0;
	ssize_t rd_chars;

	buf = malloc(BUF);
	if (!buf)
	{
		free(buf);
		return (NULL); }

	while (1)
	{
		rd_chars = read(STDIN_FILENO, &chr, 1);
		if (rd_chars == 0 || rd_chars == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[len] = chr;

		if (len == BUF - 1 || chr == '\n')
		{
			buf[len] = '\0';
			return (buf);
		}

		if (len + 1 >= BUF)
		{
			buf = increase_buf(buf, BUF + len);
			if (!buf)
			{
				free(buf);
				return (NULL); }
		}
		len++;
	}
	buf[len] = '\0';
	return (buf);
}
