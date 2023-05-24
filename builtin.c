#include "shell.h"

/**
 * env_builtin - print the environment
 *
 * Return: void
 */

void env_builtin(void)
{
	char **env = environ;
	int n;

	while (*env != NULL)
	{
		n = write(1, *env, _strlen(*env));
		write(1, "\n", 1);

		if (n < 0)
		{
			perror("write");
			exit(1);
		}
		env++;
	}
}

/**
 * exit_builtin - exit the shell
 *
 * @tokens: array of tokens
 *
 * Return: void
 */

void exit_builtin(char **tokens)
{
	int status;
	char *error;

	if (tokens[1] != NULL)
	{
		status = _atoi(tokens[1]);
		if (status == 0 && _strcmp(tokens[1], "0") != 0)
		{
			error = "Usage: exit [status]\n";
			write(STDERR_FILENO, error, _strlen(error));
		}
		else
		{
			exit(status);
		}
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

/**
 * cd_builtin - change directory
 *
 * @path: path to change to
 *
 * Return: 0 on success, 1 on failure
 */

int cd_builtin(char *path)
{
	char *new_path = NULL;
	char *oldpwd = NULL;
	char *pwd = NULL;

	if (!path || _strcmp(path, "~") == 0)
	{
		new_path = _getenv("HOME");
	}
	else if (_strcmp(path, "-") == 0)
	{
		new_path = _getenv("OLDPWD");
	}
	else
	{
		new_path = (char *)path;
	}

	oldpwd = getcwd(NULL, 0);
	if (chdir(new_path) == -1)
	{
		perror("cd");
		free(oldpwd);
		return (1);
	}

	pwd = getcwd(NULL, 0);
	if (_setenv("OLDPWD", oldpwd, 1) == -1 || _setenv("PWD", pwd, 1) == -1)
	{
		perror("setenv");
		free(oldpwd);
		free(pwd);
		return (1);
	}

	free(oldpwd);
	free(pwd);

	return (0);
}

/**
 * get_current_dir - get the current directory
 *
 * Return: the current directory
 */

char *get_current_dir()
{
	char *cwd = malloc(MAX_INPUT_SIZE);

	if (cwd == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	if (getcwd(cwd, MAX_INPUT_SIZE) == NULL)
	{
		perror("Failed to getcwd");
		exit(EXIT_FAILURE);
	}
	return (cwd);
}
