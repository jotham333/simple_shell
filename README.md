This header file contains the declarations for the functions and variables used in the shell. The shell is a simple command-line interpreter that can be used to run other programs.

Functions
The following functions are provided in the shell header file:

env_builtin(): This function prints the environment variables.
exit_builtin(): This function exits the shell.
cd_builtin(): This function changes the current directory.
get_current_dir(): This function returns the current directory.
execute_command(): This function executes a command.
process_input(): This function processes the user input.
_strtok(): This function splits a string into tokens.
tokenize_command(): This function splits a command into tokens.
trim_whitespace(): This function removes whitespace from the beginning and end of a string.
_getenv(): This function gets the value of an environment variable.
_getline(): This function reads a line from a file.
_unsetenv(): This function unsets an environment variable.
_setenv(): This function sets an environment variable.
_strlen(): This function gets the length of a string.
_strcmp(): This function compares two strings.
_strncmp(): This function compares two strings for a specified number of characters.
_strcspn(): This function gets the length of the longest prefix of a string that does not contain any characters from another string.
_strcpy(): This function copies a string.
_strcat(): This function concatenates two strings.
_strdup(): This function duplicates a string.
_strchr(): This function finds the first occurrence of a character in a string.
_isspace(): This function checks if a character is a space.
tokenizeString(): This function splits a string into tokens using a specified delimiter.
sigint_handler(): This function handles the SIGINT signal.
_atoi(): This function converts a string to an integer.
print_prompt(): This function prints the shell prompt.
_realloc(): This function reallocates memory.
_memcpy(): This function copies memory.
Variables
The following variables are defined in the shell header file:

environ: This is a pointer to an array of environment variables.
MAX_INPUT_SIZE: This is the maximum size of a user input.
MAX_ARGUMENTS: This is the maximum number of arguments that can be passed to a command.
Usage
To use the shell, simply include the header file in your program and call the process_input() function. The process_input() function will read the user input and execute the appropriate command.
