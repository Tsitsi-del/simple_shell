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
	char **argv, *cmd = NULL;

	signal(SIGINT, handle_signal);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "Shell $ ", 9);
		cmd = rdcmd();
		if (!cmd)
		{
			free(cmd);
			return (0); }
		if (cmd[0] == '\0')
		{ free(cmd);
			continue; }
		argv = tokenize(cmd, " \n");
		if (!argv)
		{ perror("Failed to tokenize");
			free(cmd);
			continue; }
		if (my_strcmp(argv[0], "exit", 4) == 0)
		{ freeArgs(argv);
			free(cmd);
			exit(0); }
		else if (my_strcmp(argv[0], "env", 3) == 0)
			display_env();
		else
		{
			if (execmd(argv) != 0)
				perror(av[0]); }
		freeArgs(argv);
		free(cmd); }
	return (0); }
