#include "main.h"

/**
 * execmd - function to execute the commands
 * @av: an array of environment variables
 *
 * Return: executable commands
 */

int execmd(char **av)
{
	char *cmd = NULL;
	char *the_cmd = NULL;
	int status;
	pid_t pid;

	if (!av)
		return (-1);

	cmd = av[0];
	the_cmd = get_path(cmd);

	if (!the_cmd)
	{
		return (-1); }

	pid = fork();
	if (pid == -1)
	{
		perror("failed fork");
		free(the_cmd);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(the_cmd, av, NULL) == -1)
		{
			perror("Excution failed");
			free(the_cmd);
			exit(2);
		}
	}
	else
	{
		if (wait(&status) == -1)
			perror("Error");
	}
	free(the_cmd);
	return (0);
}
