#include "main.h"

/**
 * my_strcmp - compares two strings with n bytes
 * @str_1: first string
 * @str_2: second string
 * @n: bytes to check string
 *
 * Return: difference of two strings
 */

int my_strcmp(const char *str_1, const char *str_2, size_t n)
{

	if (str_1 == NULL || str_2 == NULL)
	{
		return (-1);
	}
	size_t x = 0;

	while (x < n && str_1[x] != '\0' && str_1[x] == str_2[x])
	{
		x++;
	}
	if (x == n)
	{
		return (0);
	}
	return (str_1[x] - str_2[x]);
}

/**
 * my_cmp_Str - function that comapred two strings
 * @str_1: first string
 * @str_2: second string
 *
 * Return: difference of strings
 */

int my_cmp_Str(const char *str_1, const char *str_2)
{
	int x = 0;

	if (str_1 == NULL || str_2 == NULL)
	{
		return (-1);
	}
	while (str_1[x] == str_2[x])
	{
		if (str_1[x] == '\0' && str_2[x] == '\0')
		{
			break;
		}
		x++;
	}
	return (str_1[x] - str_2[x]);
}
/**
 * my_strchr - function that check strings using char
 * @s: the string
 * @c: the character
 *
 * Return: char at index or NULL
 */

char *my_strchr(const char *s, int c)
{
	int index = 0;

	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			return ((char *)&s[index]);
		}
		index++;
	}
	return (NULL);
}
