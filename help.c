#include "shell.h"


/**
 * own_help -"print help
 * @args: arguments"
 * Return: 1 on success, otherwise 0.
 */

int own_help(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};

	long unsigned int o;
	(void)(**args);

	o = 0;
	printf("\n---help simple_shell---\n");
	printf("Type a command and its arguments, then hit enter\n");
	printf("Built-in commands:\n");

	for (; o < sizeof(builtin_func_list) / sizeof(char *); o++)
	{
		printf("  -> %s\n", builtin_func_list[o]);
	}
	printf("Use the man command for information on other programs.\n\n");
	return (-1);
}
