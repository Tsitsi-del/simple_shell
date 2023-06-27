#include "main.h"
/**
 * main - entry point
 * Description: simple shell
 * @argc: counts the number of args
 * @av: a string of char arrays
 * Return: 0 (success)
 */

int main(__attribute((unused)) int argc, char **av)
{
	char *cmd = NULL;
	char **argv;
	ssize_t num_byts;

	while (1)
	{
		num_byts = write(STDOUT_FILENO, "Shell $ ", 9);
		if (num_byts == -1)
			perror("Error");
		cmd = rdcmd();
		if (cmd == NULL)
			break;
		if (cmd[0] == '\0')
			continue;

		argv = tokenize(cmd, " \n");

		if (argv == NULL)
		{
			perror("Failed to tokenize");
			free(cmd);
			continue;
		}
		if (my_strcmp(argv[0], "Exit", 4) == 0)
		{
			free(argv);
			free(cmd);
			break;
		}
		else if (my_strcmp(argv[0], "env", 3) == 0)
			display_env();
		else
		{
			if (execmd(argv) != 0)
				perror(av[0]);
		}
		free(argv);
		free(cmd);
	}
	return (0);
}
