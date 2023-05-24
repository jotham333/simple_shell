#include "shell.h"



/**
 * execute_command - execute a command
 *
 * @tokens: array of tokens
 *
 * Return: void
 */


int execute_command(char **tokens)
{
	char *path, *path_copy, *token;
	pid_t pid;
	int status;
	char bin_path[MAX_INPUT_SIZE];

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
		return (-1);
	}
	if (pid == 0)
	{
		if (tokens[0][0] == '/')
		{
			execve(tokens[0], tokens, NULL);
		}
		else
		{
			path = _getenv("PATH");
			path_copy = _strdup(path);
			token = _strtok(path_copy, ":");

			while (token != NULL)
			{
				_strcpy(bin_path, token);
				_strcat(bin_path, "/");
				_strcat(bin_path, tokens[0]);
				execve(bin_path, tokens, NULL);
				token = _strtok(NULL, ":");
			}
			free(path_copy);
			perror(tokens[0]);
			exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, &status, 0);
	return (0);
}




/**
 * process_input - processes user command
 *
 * @input: pointer to user command input
 *
 * Return: nothing
 */

void process_input(char *input)
{
	char *commands[MAX_INPUT_SIZE];
	int num_commands = 0, cmd;
	char *command;
	char *path;
	char *current_command;
	char *tokens[MAX_INPUT_SIZE];

	command = _strtok(input, ";");
	while (command != NULL)
	{
		commands[num_commands] = command;
		num_commands++;
		command = _strtok(NULL, ";");
	}

	for (cmd = 0; cmd < num_commands; cmd++)
	{
		current_command = commands[cmd];
		trim_whitespace(current_command);
		tokenize_command(current_command, tokens);

		if (_strcmp(tokens[0], "env") == 0)
		{
			env_builtin();
		} else if (_strcmp(tokens[0], "exit") == 0)
		{
			exit_builtin(tokens);
			break;
		} else if (_strcmp(tokens[0], "cd") == 0)
		{
			path = tokens[1];
			cd_builtin(path);
		} else
		{
			execute_command(tokens);
		}
	}
}
