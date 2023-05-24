#include "shell.h"

int main(void)
{
	int interactive = isatty(STDIN_FILENO);

	if (interactive)
	{
		run_interactive_mode();
	}
	else
	{
		run_noninteractive_mode();
	}

	return 0;
}
