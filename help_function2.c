#include "main.h"

/**
 *display_env - displays the current env
 */

void display_env(void)
{
	char **env = environ;
	size_t len;
	int x = 0;
	ssize_t num_byts;

	while (env[x] != NULL)
	{
		len = strlen(env[x]);
		num_byts = write(STDOUT_FILENO, env[x], len);
		if (num_byts == -1)
		{
			perror("Error");
		}
		num_byts = write(STDOUT_FILENO, "\n", 1);
		if (num_byts == -1)
			perror("Error");
		x++;
	}
}

/**
 * increase_buf - increases the buffer
 * @buf: the buffer
 * @len: the length of the buffer
 * Return: the newly allocated buffer
 */

char *increase_buf(char *buf, size_t len)
{
	char *buf_new;

	buf_new = my_realloc(buf, BUF, BUF + len);

	if (buf_new == NULL)
	{
		free(buf);
		return (NULL);
	}
	return (buf_new);
}
