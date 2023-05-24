#include "shell.h"

void run_interactive_mode()
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
			perror("Failed to getline");
			exit(EXIT_FAILURE);
		}

		if (bytes_read == 1)
			continue;

		input[strcspn(input, "\n")] = '\0';
		process_input(input);
		free(input);
		input = NULL;
		len = 0;
		fflush(stdout);
	}
}

void run_noninteractive_mode()
{
	char *input = NULL;
	size_t len = 0;
	ssize_t bytes_read;

	signal(SIGINT, sigint_handler);

	while ((bytes_read = _getline(&input, &len, stdin)) != -1)
	{
		if (bytes_read == 1)
			continue;

		input[strcspn(input, "\n")] = '\0';
		process_input(input);
		free(input);
		input = NULL;
		len = 0;
		fflush(stdout);
	}
}
