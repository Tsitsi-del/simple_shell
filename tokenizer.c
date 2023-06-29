#include "main.h"

/**
 * tokenize - func that breaks a string down to small parts
 * @cmd: the command to be exec
 * @delim: a char that seperates parts of a str
 * Return: returns the array of the tokenized string
 */
char **tokenize(char *cmd, const char *delim)
{
	char *token = NULL;
	char **argv;
	size_t index = 0;
	size_t q, token_len = 0;

	if (!cmd)
		return (NULL);
	token_len = num_tokens(cmd, delim);
	argv = malloc(sizeof(char *) * (token_len + 1));

	if (!argv)
	{
		free(cmd);
		return (NULL);
	}
	token = strtok(cmd, delim);

	while (token)
	{
		argv[index] = my_strdup(token);
		if (argv[index] == NULL)
		{
			for (q = 0; q < index; q++)
				freeArgs(argv);
			free(argv);
			free(cmd);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	argv[index] = NULL;
	return (argv);
}

/**
 * freeArgs - free memory in array of args
 * @args: array to be freed
 */

void freeArgs(char **args)
{
	 size_t i = 0;

	 while (args[i] != NULL)
	 {
		 free(args[i]);
		 i++;
	 }
	 free(args);
}
