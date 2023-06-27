#include "main.h"

/**
 * my_strdup - function to duplicate a string
 * @str: the string
 *
 * Return: string
 */

char *my_strdup(const char *str)
{
	char *s;
	int len;
	int x;

	if (str == NULL)
	{
		return (NULL);
	}

	len = my_strlen(str);

	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
	{
		return (NULL);
	}
	for (x = 0; x <= len; x++)
	{
		s[x] = str[x];
	}
	return (s);
}

/**
 * my_strlen - function that calc len of string
 * @str: the string
 *
 * Return: len of string
 */

int my_strlen(const char *str)
{
	int i;

	for (i = 0; *str != '\0'; i++)
	{
		str++;
	}
	return (i);
}

/**
 * my_strcat - function to concatenate two strings
 * @dest: where to copy the string
 * @src: source of the string
 *
 * Return: string
 */

char *my_strcat(char *dest, const char *src)
{
	char *s = dest;

	while (*s != '\0')
	{
		s++;
	}
	while (*src != '\0')
	{
		*s = *src;
		s++;
		src++;
	}
	*s = '\0';
	return (dest);
}
/**
 * my_strcpy - function to copy a string
 * @dest: where string is copied
 * @src: source of the string
 *
 * Return: string copied
 */

char *my_strcpy(char *dest, const char *src)
{
	int count = 0;

	if (src == NULL)
	{
		return (dest);
	}

	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';

	return (dest);
}
