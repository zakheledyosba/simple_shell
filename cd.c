#include "shell.h"


/**
 * own_cd - "changes the working directory of the current shell
 * @args: directory"
 *
 * Return: 1 one success, otherwise 0.
 */

int own_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error in own_cd.c: changing directory\n");
		}
	}

	return (-1);
}
