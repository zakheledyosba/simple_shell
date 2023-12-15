#include "shell.h"

/**
 * shell_interactive -"command line interpreter"
 * Return: void
 */

void shell_interactive(void)
{
	char *line, **args;
	int status = -1;

	do {
	printf("simple_prompt$ ");
	line = read_line();
	args = split_line(line);
	status = execute_args(args);

	free(line);
	free(args);

	if (status >= 0)
	{
	exit(status);
	}
	} while (status == -1);
}
