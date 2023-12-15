#include "shell.h"


/**
 * execute_args -"check if the command is a builtin or a process
 * @args: command"
 * Return: 1 on sucess, 0 otherwise
 */

int execute_args(char **args)
{
	char *builtin_func_list[] = {
	"cd",
	"env",
	"help",
	"exit"
	};

	int (*builtin_func[])(char **) = {
	&own_cd,
	&own_env,
	&own_help,
	&own_exit
	};

	size_t o = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}

	for (; o < sizeof(builtin_func_list) / sizeof(char *); o++)
	{
		if (strcmp(args[0], builtin_func_list[o]) == 0)
			return ((*builtin_func[o])(args));
	}
	return (new_process(args));
}
