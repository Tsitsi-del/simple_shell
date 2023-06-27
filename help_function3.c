#include "main.h"
/**
 * num_tokens - function that counts number of tokens
 * @cmd: command
 * @delim: a char that seperates parts of a str
 * Return: number of tokens
 */
size_t num_tokens(char *cmd, const char *delim)
{
	char *cpy_cmd;
	char *token;
	size_t num = 0;

	if (!cmd)
		return (NULL);
	cpy_cmd = my_strdup(cmd);
	if (!cpy_cmd)
		return (0);
	token = strtok(cpy_cmd, delim);

	while (token != NULL)
	{
		num++;
		token = strtok(NULL, delim);
	}
	free(cpy_cmd);
	return (num);
}
