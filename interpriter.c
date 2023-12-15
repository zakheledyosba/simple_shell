#include "shell.h"

/**
 * shell_no_interactive -"unix command line interpreter"
 * Return: void
 */

void shell_no_interactive(void)
{
	int status = -1;
	char **args;
	char *line;

	do {
	line = read_stream();
	args = split_line(line);
	status = execute_args(args);
	free(line);
	free(args);

	if (status >= 0)
		exit(status);
	} while (status == -1);
}
