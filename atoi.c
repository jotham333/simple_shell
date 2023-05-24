#include "shell.h"




/**
 * print_prompt - prompt the user for input
 *
 * Return: nothing
 */


void print_prompt(void)
{
	char *cwd = get_current_dir();

	write(STDOUT_FILENO, "cisfun:", _strlen("cisfun:"));
	write(STDOUT_FILENO, cwd, _strlen(cwd));
	write(STDOUT_FILENO, "$ ", 2);
	free(cwd);
}


/**
 * sigint_handler - print a newline when ctrl + c is pressed
 *
 * @signal: signal of the function
 *
 * Return: nothing
 */

void sigint_handler(int signal)
{
	(void)signal;

	write(1, "\n", 1);
	fflush(stdout);
}


/**
 * _atoi - extract integer from string
 * @str: the string argument
 *
 * Return: type integer
 */

int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;
	int digit;

	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
			{
				break;
			}

			i++;
			continue;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			digit = str[i] - '0';
			result = result * 10 + digit;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z') ||
				(str[i] >= 'A' && str[i] <= 'Z'))
			break;
		i++;

	}

	return (sign * result);

}
