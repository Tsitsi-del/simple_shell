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
	ssize_t num_byts;

	while (1)
	{
		num_byts = write(STDOUT_FILENO, "Shell $ ", 9);
		if (num_byts == -1)
		{ perror("Error");
			continue; }
		cmd = rdcmd();
		if (!cmd)
		{
			if (feof(stdin))
			{ perror("reached end of file");
				exit(EXIT_FAILURE); }
			else
			{ perror("failed to read command");
				break; }}
		new_lineremoved(cmd);
		if (cmd[0] == '\0')
		{ free(cmd);
			continue; }
		argv = tokenize(cmd, " \n");
		if (!argv)
		{ perror("Failed to tokenize");
			free(cmd);
			continue; }
		if (my_strcmp(argv[0], "exit", 4) == 0)
		{ free(argv);
			free(cmd);
			break; }
		else if (my_strcmp(argv[0], "env", 3) == 0)
			display_env();
		else
		{
			if (execmd(argv) != 0)
				perror(av[0]); }
		free(argv);
		free(cmd); }
	return (0); }
