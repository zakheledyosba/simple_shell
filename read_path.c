#include "shell.h"

/**
 * read_stream - "read a line from the path"
 * Return: pointer that points the read line
 */

char *read_stream(void)
{
	int bufsize = 1024;
	int o = 0;
	char *line;
	int character;

	line = malloc(sizeof(char) * bufsize);

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}

	while (1)
	{

		character = getchar();

		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		else if (character == '\n')
		{
			line[o] = '\0';
			return (line);
		}

		else
		{
			line[o] = character;
		}
		o++;

		if (o >= bufsize)
		{
			bufsize += bufsize;
			line = realloc(line, bufsize);
		}

		if (line == NULL)
		{
			fprintf(stderr, "reallocation error in read_stream");
			exit(EXIT_FAILURE);
		}
	}

}
