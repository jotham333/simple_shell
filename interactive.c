#include "shell.h"


/**
 * run_interactive_mode - runs shell program in interactive mode
 *
 * Return: nothing
 */


void run_interactive_mode(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t bytes_read;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		print_prompt();

		bytes_read = _getline(&input, &len, stdin);
		if (bytes_read == -1)
		{
			_putchar('\n');
			exit(EXIT_FAILURE);
		}

		if (bytes_read == 1)
			continue;

		input[_strcspn(input, "\n")] = '\0';
		process_input(input);
		free(input);
		input = NULL;
		len = 0;
		fflush(stdout);
	}
}




/**
 * run_noninteractive_mode - run shell program on non-interactive mode
 *
 * Return: nothing
 */

void run_noninteractive_mode(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t bytes_read;

	signal(SIGINT, sigint_handler);

	while ((bytes_read = _getline(&input, &len, stdin)) != -1)
	{
		if (bytes_read == 1)
			continue;

		input[_strcspn(input, "\n")] = '\0';
		process_input(input);
		free(input);
		input = NULL;
		len = 0;
		fflush(stdout);
	}
}
