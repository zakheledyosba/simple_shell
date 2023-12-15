#include "shell.h"

/**
 * own_env -"function that prints envr variables
 * @args: arguments"
 * Return: 1 on success, otherwise 0.
 */

int own_env(char **args)
{
	int o = 0;
	(void)(**args);

	while (environ[o])
	{
		write(STDOUT_FILENO, environ[o], strlen(environ[o]));
		write(STDOUT_FILENO, "\n", 1);
		o++;
	}
	return (-1);
}
