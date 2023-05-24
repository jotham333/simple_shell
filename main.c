#include "shell.h"

/**
 * main - the main function of the program
 *
 * Return: 0 always successful
 */


int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t bytes_read;
	int interactive =  isatty(STDIN_FILENO);

	signal(SIGINT, sigint_handler);

	while (1)
	{
		if (!interactive)
		{
			break;
		}

		print_prompt();

		bytes_read = _getline(&input, &len, stdin);
		if (bytes_read == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (bytes_read == 1)
		{
			continue;
		}

		input[_strcspn(input, "\n")] = '\0';

		process_input(input);

		free(input);
		input = NULL;
		len = 0;

		fflush(stdout);
	}

	return (0);
}
