#include "main.h"

/**
 * my_getenv -function that retrieves the val from the env var
 *
 * @env_name: the name of the var containing the exec cmd
 * Return: the var containning the cmd
 */

char *my_getenv(const char *env_name)
{
	char *val = NULL;
	char **env = environ;
	size_t env_len = 0;
	char *delim;
	size_t index;
	size_t val_len = 0;

	if (!env_name)
		return (NULL);
	env_len = my_strlen(env_name);

	for (index = 0; *env != NULL; index++)
	{
		if (my_strcmp(env_name, env[index], env_len) == 0)
		{
			delim = my_strchr(env[index], '=');
			if (delim)
			{
				val_len = my_strlen(delim + 1);
				val = malloc(sizeof(char) * (val_len + 1));
				if (!val)
				{ free(val);
					return (NULL); }
				my_strcpy(val, delim + 1);
				return (val);
			}
		}
	}
	free(val);
	return (NULL);
}

/**
 * crt_path - creates the path of a command
 * @directory: directory of the command
 * @cmd: the exec command
 * Return: returns the full path of the cmd
 */

char *crt_path(char *directory, char *cmd)
{
	char *full_path;

	full_path = malloc(my_strlen(directory) + my_strlen(cmd) + 2);
	if (!full_path)
	{
		free(full_path);
		return (NULL); }

	my_strcpy(full_path, directory);
	my_strcpy(full_path, "/");
	my_strcat(full_path, cmd);
	
	return (full_path);
}

/**
 *my_realloc - reallocates memory
 *@ptr: points to the memory of the string
 *@o_size: represents the old size of the str
 *@nw_size: represents the new size allocated
 *Return: returns the new size of str allocated
 */

void *my_realloc(void *ptr, size_t o_size, size_t nw_size)
{
	char *nw;
	size_t index;

	if (nw_size == o_size)
		return (ptr);
	if (nw_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(nw_size));

	nw = malloc(nw_size);
	if (!nw)
		return (NULL);
	if (nw_size < o_size)
	{
		for (index = 0; index < nw_size; index++)
		{
			*(nw + index) = *((char *)ptr + index);
		}
	}
	if (nw_size > o_size)
	{
		for (index = 0; index < o_size; index++)
		{
			*(nw + index) = *((char *)ptr + index);
		}
	}
	free(ptr);
	return (nw);
}
