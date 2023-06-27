#include "main.h"

/**
 * get_path - function to get the path of the exe command
 * @cmd: the command to be executed
 * Return: the exe command on success or NULL
 *
 */

char *get_path(char *cmd)
{
	char *path, *token, *copy_path;
	char *path_cmd;
	struct stat buf;

	path = my_getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	copy_path = my_strdup(path);
	if (copy_path == NULL)
	{
		return (NULL);
	}
	token = strtok(copy_path, ":");

	while (token)
	{
		path_cmd = crt_path(token, cmd);
		if (path_cmd == NULL)
		{
			free(copy_path);
			return (NULL);
		}
		if (stat(path_cmd, &buf) == 0)
		{
			free(copy_path);
			return (path_cmd);
		}
		free(path_cmd);
		token = strtok(NULL, ":");
	}
	free(copy_path);

	if (stat(cmd, &buf) == 0)
	{
		return (cmd);
	}
	return (NULL);
}
