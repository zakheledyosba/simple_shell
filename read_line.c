#include "shell.h"


/**
 * read_line -"read a line from stdin"
 * Return: pointer that points to a string with line content
 */

char *read_line(void)
{
	size_t bufsize = 0;
	char *line;

	line = NULL;

	if (getline(&line, &bufsize, stdin) == -1)
	{
	if (feof(stdin))
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	else
	{
	free(line);
	perror("error while reading the line from stdin");
	exit(EXIT_FAILURE);
	}
	}
	return (line);
}
