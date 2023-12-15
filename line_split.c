#include "shell.h"


/**
 * split_line -"split a string into number of strings
 * @line: string to be splited"
 * Return: pointer that points to the new array
 */

char **split_line(char *line)
{
	int bufsize = 64;
	int o = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
	if (token[0] == '#')
		break;

	tokens[o] = token;
	o++;

	if (o >= bufsize)
	{
		bufsize += bufsize;
		tokens = realloc(tokens, bufsize * sizeof(char *));

	if (!tokens)
	{
		fprintf(stderr, "reallocation error in split_line: tokens");
		exit(EXIT_FAILURE);
	}
	}

	token = strtok(NULL, TOK_DELIM);
	}

	tokens[o] = NULL;
	return (tokens);
}
