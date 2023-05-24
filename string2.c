#include "shell.h"

/**
 * _strdup - duplicate a string
 * @str: string to duplicate
 * Return: pointer to duplicate string
 */
char *_strdup(char *str)
{
	char *dup;
	int i;

	if (str == NULL)
		return (NULL);

	dup = malloc(sizeof(char) * (_strlen(str) + 1));
	if (dup == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		dup[i] = str[i];
	}
	return (dup);
}

/**
 * _strchr - search for a character in a string
 * @str: pointer to the string
 * @character: the character to be searched
 * Return: pointer to string if success and NULL otherwise
 */

char *_strchr(char *str, char character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			return (str);
		}
		str++;
	}
	if (character == '\0')
	{
		return (str);
	}
	return (NULL);
}

/**
 * _strcat - concatenate two strings
 * @destination: pointer to the string to be appended into
 * @source: pointer to the string to append
 * Return: pointer to the destination
 */

char *_strcat(char *destination, char *source)
{
	char *ptr;

	if (destination == NULL)
		return (source);

	ptr = destination;
	while (*ptr != '\0')
		ptr++;

	while (*source != '\0')
	{
		*ptr = *source;
		source++;
		ptr++;
	}
	*ptr = '\0';
	return (destination);
}

/**
 * _strcpy - copy a string to a destination
 * @destination: pointer to the destination
 * @source: pointer to the source to copy from
 * Return: pointer to te destination
 */

char *_strcpy(char *destination, char *source)
{
	int index = 0;

	while (source[index] != '\0')
	{
		destination[index] = source[index];
		index++;
	}

	destination[index] = '\0';

	return (destination);
}



/**
 * _isspace - checks for space in a string
 *
 * @c: the character to check for
 *
 * Return: 1 if space was found and 0 otherwise
 */


int _isspace(int c)
{

	switch (c)
	{
		case ' ':
		case '\t':
		case '\n':
		case '\r':
		case '\f':
		case '\v':
			return (1);
		default:
			return (0);
	}
}
