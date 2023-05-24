#include "shell.h"



/**
 * tokenize_command - tokenize a command
 *
 * @command: pointer to command
 *
 * @tokens: pointer to array of tokens
 *
 * Return: nothing
 */

void tokenize_command(char *command, char *tokens[])
{
	char *token = _strtok(command, " ");
	int i = 0;

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = _strtok(NULL, " ");
	}
	tokens[i] = NULL;
}


/**
 * _strtok - tokenizes string
 *
 * @str: pointer to the string to be tokenize
 *
 * @delim: pointer to the character to look out for
 *
 * Return: pointer to the tokenize string
 */


char *_strtok(char *str, char *delim)
{
	static char *last;
	char *token;

	if (str != NULL)
	{
		last = str;
	}
	else
	{
		str = last;
	}
	while (*str && _strchr(delim, *str))
	{
		str++;
	}
	if (*str == '\0')
	{
		return (NULL);
	}
	token = str;
	while (*str && !_strchr(delim, *str))
	{
		str++;
	}
	if (*str)
	{
		*str++ = '\0';
	}
	last = str;
	return (token);
}

/**
 * trim_whitespace - terminate whitespaces in command
 *
 * @command: pointer to the command
 *
 * Return: nothing
 */


void trim_whitespace(char *command)
{
	char *end;

	while (_isspace(*command))
	{
		command++;
	}
	end = command + _strlen(command) - 1;
	while (end > command && _isspace(*end))
	{
		end--;
	}
	*(end + 1) = '\0';
}
